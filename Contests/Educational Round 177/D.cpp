// Codeforces Educational Round 177
// Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define s second
#define f first

const int MOD = 998244353;
const int MAXN = 5e5;
vector<int> f(MAXN + 1, 1), rf(MAXN + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; a *= a, a %= MOD, b /= 2) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int comb(int n, int r) {
    int res = f[n] * rf[r] % MOD;
    res *= rf[n - r], res %= MOD;
    return res;
}

void solve() {
    vector<int> a(26);
    int tot = 0, n = 26;
    for (auto &x : a) {
        cin >> x;
        tot += x;
        n -= x == 0;
    }
    sort(a.rbegin(), a.rend());

    int m = f[tot / 2] * f[tot - tot / 2] % MOD;
    for (auto x : a) m *= rf[x], m %= MOD;

    vector<int> dp(tot + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        auto ndp = dp;
        for (int j = 0; j <= tot - a[i]; j++) {
            ndp[j + a[i]] += dp[j];
            ndp[j + a[i]] %= MOD;
        }
        dp = ndp;
    }
    // for (auto x : dp) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }

    int ans = m * dp[tot / 2] % MOD;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) f[i] = f[i - 1] * i % MOD;
    for (int i = 1; i <= MAXN; i++) rf[i] = binexp(f[i]);

    int t = 1;
    cin >> t;
    while (t--) solve();
}