// CSES Dynamic Programming: Edit Distance

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i != 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            if (j != 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            if (i != 0 && j != 0)
                dp[i][j] =
                    min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    }
    // for (auto x : dp) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }
    cout << dp[n][m] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}