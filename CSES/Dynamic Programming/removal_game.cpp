// CSES Dynamic Programming: Removal Game

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pfs(1, 0);
    for (auto x : a) pfs.push_back(pfs.back() + x);
    vector<vector<int>> dp(n + 1, vector<int>(n));
    for (int i = 0; i < n; i++) dp[1][i] = a[i];
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i + l <= n; i++) {
            int sm = pfs[i + l] - pfs[i];
            dp[l][i] = max(sm - dp[l - 1][i], sm - dp[l - 1][i + 1]);
        }
    }
    cout << dp[n][0] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}