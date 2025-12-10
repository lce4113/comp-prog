// CSES Dynamic Programming: Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<pair<int, int>>> lst(n + 1,
                                       vector<pair<int, int>>(m + 1, {-1, -1}));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i != 0 && dp[i - 1][j] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j];
                lst[i][j] = lst[i - 1][j];
            }
            if (j != 0 && dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                lst[i][j] = lst[i][j - 1];
            }
            if (i != 0 && j != 0 &&
                dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]) > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - 1] + (a[i - 1] == b[j - 1]);
                lst[i][j] = {i - 1, j - 1};
            }
        }
    }
    cout << dp[n][m] << '\n';
    pair<int, int> c = {n, m};
    vector<int> ans;
    while (c.f != -1) {
        if (c.f != n || c.s != m) ans.push_back(a[c.f]);
        c = lst[c.f][c.s];
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}