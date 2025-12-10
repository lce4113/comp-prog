// CSES Dynamic Programming: Elevator Rides

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<pair<int, int>> dp(1 << n, {1e9, 1e9});
    dp[0] = {1, 0};
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) continue;
            auto [r, l] = dp[i - (1 << j)];
            if (l + a[j] > k) {
                r++;
                l = a[j];
            } else {
                l += a[j];
            }
            auto [cr, cl] = dp[i];
            if (r < cr || r == cr && l < cl) dp[i] = {r, l};
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        // for (int j = 0; j < n; j++) {
        //     cout << ((i & (1 << j)) ? 1 : 0);
        // }
        // cout << ": ";
        // cout << dp[i].f << ' ' << dp[i].s << '\n';
    }
    cout << dp.back().f << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}