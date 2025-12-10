// BAPC Preliminaries 2017: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[1][1] = 1;
    for (int h = 2; h <= n; h++) {
        dp[h] = dp[h - 1];
        dp[h][h]++, dp[h][h] %= MOD;
        for (int w = h + 1; w <= m; w++) {
            dp[h][w] = 0;
            for (int i = 1; w - i >= 1; i++) {
                dp[h][w] += dp[h][w - i] * dp[h - 1][i];
                dp[h][w] %= MOD;
            }
        }
    }
    cout << (dp[n][m] - dp[n - 1][m] + MOD) % MOD << '\n';
}