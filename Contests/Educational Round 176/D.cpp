// Codeforces Educational Round 176: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<vector<int>> dp(60, vector<int>(60, 1e18));

void solve() {
    int x, y;
    cin >> x >> y;
    int ans = 1e18;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            if (x / (1ll << i) == y / (1ll << j)) ans = min(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    dp[0][0] = 0;
    for (int k = 1; k < 60; k++) {
        for (int i = 60 - 1; i >= 0; i--) {
            for (int j = 60 - 1; j >= 0; j--) {
                if (i >= k) dp[i][j] = min(dp[i][j], dp[i - k][j] + (1ll << k));
                if (j >= k) dp[i][j] = min(dp[i][j], dp[i][j - k] + (1ll << k));
                // cout << dp[i][j] << '\n';
            }
        }
    }
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
    //     }
    // }
    cout << '\n';

    int t = 1;
    cin >> t;
    while (t--) solve();
}