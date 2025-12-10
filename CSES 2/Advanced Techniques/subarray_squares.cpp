// CSES Advanced Techniques: Subarray Squares

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pfs(1, 0);
    for (auto x : a) pfs.push_back(pfs.back() + x);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int sm = pfs[i + 1] - pfs[j];
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            dp[i + 1][i + 1] = min(dp[i + 1][i + 1], dp[i][j] + sm * sm);
            cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }
    cout << dp[n][n] << '\n';
}