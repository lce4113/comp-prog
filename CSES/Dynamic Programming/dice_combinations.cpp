// CSES Dynamic Programming: Dice Combinations

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) dp[i] += dp[i - j], dp[i] %= MOD;
        }
    }
    cout << dp[n] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}