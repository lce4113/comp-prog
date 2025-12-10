// CSES Dynamic Programming: Coin Combinations II

#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int dp[k + 1];
    for (int i = 0; i <= k; i++) dp[i] = 0;
    dp[0] = 1;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < k; i++) {
            if (i + a[0] > k) continue;
            int nxt = i + a[j];
            if (nxt <= k) {
                dp[nxt] += dp[i];
                if (dp[nxt] >= MOD) dp[nxt] -= MOD;
            }
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