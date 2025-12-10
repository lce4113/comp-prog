// ICPC Pacific Northwest Regional 2015
// Problem J: Olympics

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
#define all(x) x.begin(), x.end()

map<pair<int, bool>, int> dp;

int e, a, b;

int rec(int x, bool L) {
    if (dp.count({x, L})) return dp[{x, L}];
    if (x <= min(a, b)) return L + 1;
    dp[{x, L}] = rec(x - a, L | 0) + rec(x - b, 1);
    if (dp[{x, L}] >= 1e18) return 1e18;
    return dp[{x, L}];
}

void solve() {
    cin >> e >> a >> b;
    // vector<int> a(n);
    // for (auto &x : a) cin >> x;
    // if (e / min(a, b) >= 60) {
    //     cout << fixed << setprecision(6) << 0.0 << '\n';
    //     return;
    // }
    long double ans = rec(e, 0);
    // cout << ans << '\n';
    // if (ans == -1) cout << fixed << setprecision(6) << 0 << '\n';
    // for (auto x : dp) cout << x.f << ' ' << x.s << '\n';
    ans = ans == 1 ? 225.0 / 2 : 200.0 / ans;
    cout << fixed << setprecision(6) << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
