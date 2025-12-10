// CSES Dynamic Programming: Array Description

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;
const int MAXN = 1e6;

int dp[MAXN + 1][3];

void solve() {
    int n;
    cin >> n;
    cout << (dp[n][0] + dp[n][2]) % MOD << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // 0: __, 1: | |, 2: _ _, 3: _ ||, 4: || _, 5: || ||
    for (int i = 0; i <= MAXN; i++) {
        for (int j = 0; j < 3; j++) dp[i][j] = 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < MAXN; i++) {
        dp[i + 1][0] += dp[i][0] + dp[i][1] + dp[i][2];
        dp[i + 1][1] += dp[i][0] + dp[i][1] + dp[i][2];
        dp[i + 1][2] += dp[i][0] + 4 * dp[i][2];
        for (auto &x : dp[i + 1]) x %= MOD;
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}