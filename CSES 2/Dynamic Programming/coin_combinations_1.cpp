// CSES Dynamic Programming: Coin Combinations I

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0) dp[i] += dp[i - a[j]], dp[i] %= MOD;
        }
    }
    cout << dp[k] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}