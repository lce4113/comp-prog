// CSES Mathematics: Dice Probability

#include <bits/stdc++.h>
using namespace std;

#define int long double

const int MAXN = 100;

int32_t main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> dp(6 * MAXN + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> ndp(6 * MAXN + 1);
        for (int k = 0; k <= 6 * MAXN; k++) {
            for (int j = 1; j <= 6 && k + j <= 6 * MAXN; j++) {
                ndp[k + j] += dp[k];
            }
        }
        dp = ndp;
    }
    int ans = 0;
    for (int i = a; i <= b; i++) ans += dp[i];
    ans /= pow(6, n);
    cout << fixed << setprecision(6) << ans << '\n';
}