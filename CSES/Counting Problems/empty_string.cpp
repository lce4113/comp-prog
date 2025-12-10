// CSES Counting Problems: Empty String

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int MAXN = 500;
vector<vector<int>> C(MAXN + 1, vector<int>(MAXN + 1));
vector<int> f(2 * MAXN + 1, 1), rf(2 * MAXN + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= 2 * MAXN; i++) f[i] = f[i - 1] * i % MOD;
    for (int i = 1; i <= 2 * MAXN; i++) rf[i] = binexp(f[i]);
    for (int i = 0; i <= MAXN; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = (f[i] * rf[i - j] % MOD) * rf[j] % MOD;
        }
    }

    string a;
    cin >> a;
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(n, 0));
    for (int l = 0; l < n; l++) dp[0][l] = 1;
    for (int len = 2; len <= n; len += 2) {
        for (int l = 0; l + len - 1 < n; l++) {
            if (a[l] == a[l + len - 1]) {
                dp[len][l] += dp[len - 2][l + 1];
                dp[len][l] %= MOD;
            }
            for (int m = l + 2; m + 2 <= l + len; m++) {
                if (a[l] != a[m - 1]) continue;
                int add = (dp[m - l - 2][l + 1] * dp[l + len - m][m] % MOD) *
                          C[len / 2][(m - l) / 2] % MOD;
                dp[len][l] += add, dp[len][l] %= MOD;
            }
            // cout << len << ' ' << l << ' ' << dp[len][l] << '\n';
        }
    }
    cout << dp[n][0] << '\n';
}