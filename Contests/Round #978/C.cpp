#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    dp[0] = {0, 0, 0};
    int x, y;
    for (int i = 0; i <= n; i++) {
        if (i < 1) continue;
        // .|#|.
        // .|#|#
        x = ((a[i - 1] == 'A') + (b[i - 1] == 'A') + (a[i] == 'A')) >= 2;
        // .|#|#
        // .|#|.
        y = ((a[i - 1] == 'A') + (b[i - 1] == 'A') + (b[i] == 'A')) >= 2;
        if (dp[i - 1][0] >= 0) dp[i][1] = max(dp[i - 1][0] + x, dp[i][1]);
        if (dp[i - 1][0] >= 0) dp[i][2] = max(dp[i - 1][0] + y, dp[i][2]);

        if (i < 2) continue;
        // .|.#|
        // .|##|
        x = ((b[i - 2] == 'A') + (b[i - 1] == 'A') + (a[i - 1] == 'A')) >= 2;
        // .|##|
        // .|.#|
        y = ((a[i - 2] == 'A') + (b[i - 1] == 'A') + (a[i - 1] == 'A')) >= 2;
        if (dp[i - 2][1] >= 0) dp[i][0] = max(dp[i - 2][1] + x, dp[i][0]);
        if (dp[i - 2][2] >= 0) dp[i][0] = max(dp[i - 2][2] + y, dp[i][0]);

        if (i < 3) continue;
        x = 0;
        // .|###|
        // .|...|
        x += ((a[i - 3] == 'A') + (a[i - 2] == 'A') + (a[i - 1] == 'A')) >= 2;
        // .|...|
        // .|###|
        x += ((b[i - 3] == 'A') + (b[i - 2] == 'A') + (b[i - 1] == 'A')) >= 2;
        if (dp[i - 3][0] >= 0) dp[i][0] = max(dp[i - 3][0] + x, dp[i][0]);

        x = 0;
        // .|###|.
        x += ((a[i - 3] == 'A') + (a[i - 2] == 'A') + (a[i - 1] == 'A')) >= 2;
        // .|.##|#
        x += ((b[i - 2] == 'A') + (b[i - 1] == 'A') + (b[i] == 'A')) >= 2;
        if (dp[i - 3][2] >= 0) dp[i][2] = max(dp[i - 3][2] + x, dp[i][2]);

        x = 0;
        // .|.##|#
        x += ((a[i - 2] == 'A') + (a[i - 1] == 'A') + (a[i] == 'A')) >= 2;
        // .|###|.
        x += ((b[i - 3] == 'A') + (b[i - 2] == 'A') + (b[i - 1] == 'A')) >= 2;
        if (dp[i - 3][1] >= 0) dp[i][1] = max(dp[i - 3][1] + x, dp[i][1]);
    }
    // for (auto X : dp) {
    //     for (auto Y : X) cout << Y << ' ';
    //     cout << '\n';
    // }
    cout << dp[n][0] << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}