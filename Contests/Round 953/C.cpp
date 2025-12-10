// Codeforces Round 953: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, k;

// vector<int> solve() {
void solve() {
    cin >> n >> k;
    if (k % 2) {
        // return {-1};
        cout << "NO\n";
        return;
    }
    if (n % 2 && k > 2 * (n / 2) * (n / 2 + 1)) {
        // return {-1};
        cout << "NO\n";
        return;
    }
    if (n % 2 == 0 && k > 2 * (n / 2) * (n / 2)) {
        // return {-1};
        cout << "NO\n";
        return;
    }
    vector<int> ans(n + 1, 0);
    int fv = n, bv = 1;
    int fi = 1, bi = n;
    while (fv >= bv) {
        if (k < 2 * (fv - fi)) {
            // cout << bi << ' ' << bv << '\n';
            if (k > 0) {
                while (k > 0) fi++, k -= 2;
                ans[fi] = bv++;
            }
            for (int i = 1; i <= n; i++) {
                if (ans[i] == 0) ans[i] = bv++;
            }
            break;
        }
        ans[fi] = fv;
        ans[bi] = bv;
        k -= 2 * (fv - fi);
        fi++, fv--, bi--, bv++;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    // return ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    // for (int i1 = 2; i1 <= 100; i1++) {
    //     for (int i2 = 0; i2 <= 1000; i2 += 2) {
    //         // cout << "asdf: " << i1 << ' ' << i2 << '\n';
    //         n = i1, k = i2;
    //         vector<int> ans = solve();
    //         if (ans[0] == -1) continue;
    //         int sm = 0;
    //         for (int i = 1; i <= n; i++) {
    //             sm += abs(ans[i] - i);
    //         }
    //         // cout << n << ' ' << k << ' ' << sm << '\n';
    //         // for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    //         // cout << '\n';
    //         if (sm != i2) {
    //             // cout << "sm: " << sm << ' ' << k << '\n';
    //             cout << i1 << ' ' << i2 << ' ' << sm << '\n';
    //             for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    //             cout << '\n';
    //             cout << "ohno\n";
    //             return 0;
    //         }
    //     }
    // }
    int t = 1;
    cin >> t;
    while (t--) solve();
}