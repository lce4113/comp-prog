// CSES Dynamic Programming: Two Sets II

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; a *= a, a %= MOD, b /= 2)
        if (b % 2) res *= a, res %= MOD;
    return res;
}

void solve() {
    int n;
    cin >> n;
    int N = n * (n + 1) / 2;
    if (N % 2) {
        cout << "0\n";
        return;
    }
    N /= 2;
    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = N; j >= i; j--) dp[j] += dp[j - i], dp[j] %= MOD;
    }
    cout << dp[N] * binexp(2) % MOD << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}