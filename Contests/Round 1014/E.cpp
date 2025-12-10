// Codeforces Round 1014: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; a *= a, a %= MOD, b /= 2) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int gw = 2 * (n - 2 + m - 2), w = 0;
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        if (x == 1 || x == n || y == 1 || y == m) {
            if (x == 1 && y == 1) continue;
            if (x == 1 && y == m) continue;
            if (x == n && y == m) continue;
            if (x == n && y == 1) continue;
            gw--, w += c;
        }
    }
    // cout << gw << ' ' << n * m - k - gw << '\n';
    int ans = binexp(2, n * m - k - gw);
    if (gw == 0) {
        cout << (w % 2 ? 0 : ans) << '\n';
        return;
    }
    ans *= binexp(2, gw - 1), ans %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}