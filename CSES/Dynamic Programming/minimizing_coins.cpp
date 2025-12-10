// CSES Sorting & Searching: Minimizing Coins

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> dp(k + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0) dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    cout << (dp[k] == 1e18 ? -1 : dp[k]) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}