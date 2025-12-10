// Codeforces Good Bye 2024 Round: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

map<int, int> dp;

int cnt(int num, int k) {
    if (num < k) return 0;
    if (dp.count(num)) return dp[num];
    int ans = (num % 2) + 2 * cnt(num / 2, k);
    dp[num] = ans;
    return ans;
}

void solve() {
    dp.clear();
    int n, k;
    cin >> n >> k;

    int ans = 0;
    // map<int, int> c;
    // c[n] = 1;
    // for (auto x : c) cout << x.f << ' ' << x.s << ", ";
    // cout << '\n';
    // cout << ans << '\n';
    int c = 1;
    while (n >= k) {
        if (n % 2) {
            // cout << n << '\n';
            ans += c * (n / 2 + 1);
            // cout << "m: " << c << ' ' << (n / 2 + 1) << '\n';
        }
        ans += cnt(n / 2, k) * c * ((n + 1) / 2);
        // cout << "p: " << cnt(n / 2, k) << ' ' << c << ' ' << ((n + 1) / 2)
        //      << '\n';
        // cout << ans << '\n';
        c *= 2;
        n /= 2;
    }
    cout << ans << '\n';
    // while (c.size()) {
    //     map<int, int> nxt;
    //     for (auto p : c) {
    //         int x = p.f, y = p.s;
    //         if ((x + 1) / 2 - 1 >= k) nxt[(x + 1) / 2 - 1] += y;
    //         if (x - (x + 1) / 2 >= k) {
    //             nxt[x - (x + 1) / 2] += y;
    //             ans += (x + 1) / 2 * cnt(x - (x + 1) / 2, k) * y;
    //             cout << "p: " << (x + 1) / 2 << ' '
    //                  << cnt(x - (x + 1) / 2, k) * y << '\n';
    //         }
    //         ans += (x + 1) / 2 * y;
    //         cout << "m: " << (x + 1) / 2 << ' ' << y << '\n';
    //     }
    //     c = nxt;
    //     cout << "c: ";
    //     for (auto x : c) cout << x.f << ' ' << x.s << ", ";
    //     cout << '\n';
    //     cout << ans << '\n';
    // }
    // cout << ans << '\n';
    // cout << '\n';
}

int32_t main() {
    // cout << cnt(10, 1) << '\n';
    int t = 1;
    cin >> t;
    while (t--) solve();
}