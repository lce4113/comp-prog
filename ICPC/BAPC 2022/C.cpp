// BAPC 2025: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, t, r;
    long double p;
    cin >> n >> t >> r >> p;
    vector<long double> T(n + 1), dp(n + 1, INF);
    T[0] = 0;
    for (int i = 1; i <= n; i++) {
        T[i] = (1.0 + T[i - 1] + p * r) / (1.0 - p);
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + t + T[i - j]);
        }
    }
    // for (auto x : T) cout << x << ' ';
    // cout << '\n';
    cout << fixed << setprecision(15) << dp[n] << '\n';
}