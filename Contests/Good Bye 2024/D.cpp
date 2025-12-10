// Codeforces Good Bye 2024 Round: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;

int binexp(int a, int b = MOD - 2) {
    int ans = 1;
    for (; b; a *= a, a %= MOD) {
        if (b % 2) ans *= a, ans %= MOD;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n), A, B;
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    A = a, B = b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= min(a[i], b[i]), ans %= MOD;
    }
    // for (auto y : a) cout << y << ' ';
    // cout << '\n';
    // for (auto y : b) cout << y << ' ';
    // cout << '\n';
    // cout << ans << '\n' << '\n';
    cout << ans << ' ';
    while (q--) {
        int o, x;
        cin >> o >> x;
        // cout << o << ' ' << x << '\n';
        x--;
        if (o == 1) {
            // cout << A[x] << '\n';
            int p = --upper_bound(a.begin(), a.end(), A[x]) - a.begin();
            ans *= binexp(min(a[p], b[p])), ans %= MOD;
            // ans /= min(a[p], b[p]);
            ans *= min(a[p] + 1, b[p]), ans %= MOD;
            A[x]++;
            a[p]++;
        } else {
            // cout << B[x] << '\n';
            int p = --upper_bound(b.begin(), b.end(), B[x]) - b.begin();
            // ans /= min(a[p], b[p]);
            ans *= binexp(min(a[p], b[p])), ans %= MOD;
            ans *= min(a[p], b[p] + 1), ans %= MOD;
            B[x]++;
            b[p]++;
        }
        // for (auto y : a) cout << y << ' ';
        // cout << '\n';
        // for (auto y : b) cout << y << ' ';
        // cout << '\n';
        // cout << ans << '\n' << '\n';
        cout << ans << ' ';
    }
    cout << '\n';
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}