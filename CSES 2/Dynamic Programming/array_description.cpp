// CSES Dynamic Programming: Array Description

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> dp(n, vector<int>(m));
    if (a[0] == 0) {
        for (auto &x : dp[0]) x = 1;
    } else {
        dp[0][a[0] - 1] = 1;
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (i + 1 < m) dp[j][i + 1] += dp[j - 1][i];
            dp[j][i] += dp[j - 1][i];
            if (i - 1 >= 0) dp[j][i - 1] += dp[j - 1][i];
        }
        if (a[j] != 0) {
            for (int i = 0; i < m; i++) {
                if (i != a[j] - 1) dp[j][i] = 0;
            }
        }
        for (auto &x : dp[j]) x %= MOD;
    }
    // for (auto x : dp) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }
    cout << reduce(dp[n - 1].begin(), dp[n - 1].end()) % MOD << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}