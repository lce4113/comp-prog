// CSES Counting Problems: Permutations Inversions

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 500, MAXI = MAXN * (MAXN - 1) / 2;
int dp[MAXN + 1][MAXI + 1];
int pfs[MAXN + 1][MAXI + 2];

int32_t main() {
    memset(&dp[0][0], 0, sizeof(dp));
    memset(&pfs[0][0], 0, sizeof(pfs));

    dp[1][0] = 1;
    for (int i = 0; i <= MAXI; i++) {
        pfs[1][i + 1] = (pfs[1][i] + dp[1][i]) % MOD;
    }
    for (int n = 2; n <= MAXN; n++) {
        for (int i = 0; i <= n * (n - 1) / 2; i++) {
            int R = i + 1;
            int L = max(0, i - (n - 1));
            dp[n][i] = (pfs[n - 1][R] - pfs[n - 1][L] + MOD) % MOD;
        }
        for (int i = 0; i <= MAXI; i++) {
            pfs[n][i + 1] = (pfs[n][i] + dp[n][i]) % MOD;
        }
    }

    // for (int i = 0; i <= MAXN; i++) {
    //     for (int j = 0; j <= MAXI; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for (int i = 0; i <= MAXN; i++) {
    //     for (int j = 0; j <= MAXI + 1; j++) {
    //         cout << pfs[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int n, k;
    cin >> n >> k;
    cout << dp[n][k] << '\n';
}