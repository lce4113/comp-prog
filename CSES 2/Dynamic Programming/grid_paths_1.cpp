// CSES Dynamic Programming: Grid Paths I

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = a[0][0] == '.';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '*') continue;
            if (i - 1 >= 0) dp[i][j] += dp[i - 1][j], dp[i][j] %= MOD;
            if (j - 1 >= 0) dp[i][j] += dp[i][j - 1], dp[i][j] %= MOD;
        }
    }
    cout << dp[n - 1][n - 1] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}