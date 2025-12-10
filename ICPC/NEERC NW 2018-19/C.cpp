// NEERC NW 2018-19: Problem C

#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

const int N = 2e5, Q = 5e2;
vector<int> dp[N + 1];

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if (i % 2 != n % 2) continue;
        ans += dp[(n - i * i) / 2][i], ans %= MOD;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    dp[0] = vector<int>(Q + 1, 1);
    for (int n = 1; n <= N; n++) {
        dp[n].push_back(1);
        dp[n].push_back(1);
        for (int sq = 2; sq * sq + n <= N; sq++) {
            // dp[# cells][sq] = number of ways to put # cells on sqxsq square
            // dp[#][sq] = dp[# - sq][sq] + dp[#][sq - 1]
            int c = dp[n][sq - 1];
            if (n >= sq) c = (c + dp[n - sq][sq]) % MOD;
            dp[n].push_back(c);
        }
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}