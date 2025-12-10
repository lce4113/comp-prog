#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> dp(m + 2, vector<int>(m + 1));
    for (int k = 0, i = 0; k < n; k++, i++) {
        vector<int> pos, neg;
        while (k < n && a[k] != 0) {
            // cout << k << ' ' << a[k] << '\n';
            if (a[k] > 0)
                pos.push_back(a[k]);
            else
                neg.push_back(-a[k]);
            k++;
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        // cout << i << '\n';
        for (int j = 0; j <= i; j++) {
            int x = upper_bound(pos.begin(), pos.end(), j) - pos.begin();
            int y = upper_bound(neg.begin(), neg.end(), i - j) - neg.begin();
            if (j != 0)
                dp[i + 1][j] = max(dp[i][j] + x + y, dp[i][j - 1] + x + y);
            else
                dp[i + 1][j] = dp[i][j] + x + y;
            if (j != i) dpn[j] = max(dpn[i][j], dp[j] + x + y);
            if (j != 0) dpn[j] = max(dpn[j], dp[j - 1] + x + y);
        }
    }
    int ans = 0;
    for (auto x : dp[m + 1]) ans = max(ans, x);
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie();

    int t = 1;
    // cin >> t;
    while (t--) solve();
}