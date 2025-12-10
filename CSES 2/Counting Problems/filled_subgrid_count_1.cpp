// CSES Counting Problems: Filled Subgrid Count I

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 3e3;
int dp[MAXN + 1][MAXN + 1];

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, A;
    cin >> n >> A;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < A; i++) {
        int ans = 0;
        for (int x = 0; x < n; x++) {
            dp[x][n - 1] = (a[x][n - 1] - 'A' == i);
            dp[n - 1][x] = (a[n - 1][x] - 'A' == i);
            ans += dp[x][n - 1] + dp[n - 1][x];
        }
        ans -= dp[n - 1][n - 1];
        for (int x = n - 2; x >= 0; x--) {
            for (int y = n - 2; y >= 0; y--) {
                dp[x][y] = 0;
                if (a[x][y] - 'A' == i)
                    dp[x][y] = 1 + min(min(dp[x + 1][y], dp[x][y + 1]),
                                       dp[x + 1][y + 1]);
                ans += dp[x][y];
            }
        }
        cout << ans << '\n';
    }
}