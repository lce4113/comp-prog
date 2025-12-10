// CSES Dynamic Programming: Rectangle Cutting

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    for (int i = 0; i < min(n + 1, m + 1); i++) dp[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[n][m] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}