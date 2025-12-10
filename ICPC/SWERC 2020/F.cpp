// SWERC 2020-21: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int r, n, m;
    cin >> r >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(n + 2));
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j - 1];
            if (i == r) continue;
            dp[i][j] += dp[i - 1][j] * j, dp[i][j] %= m;
            dp[i][j] += dp[i - 1][j + 1] * (j + 1) * j / 2, dp[i][j] %= m;
        }
        // cout << i << ": ";
        // for (auto x : dp[i]) cout << x << ' ';
        // cout << '\n';
    }
    cout << dp[n][1] << '\n';
}