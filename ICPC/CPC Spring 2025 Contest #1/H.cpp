// Columbia Programming Camp
// Spring 2025 Contest #1
// Problem L

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int MOD;

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; a *= a, a %= MOD, b /= 2)
        if (b % 2) res *= a, res %= MOD;
    return res;
}

int comb(int n, int k, const vector<int> &fact, const vector<int> &fact_inv) {
    int ans = fact[n];
    ans *= fact_inv[k], ans %= MOD;
    ans *= fact_inv[n - k], ans %= MOD;
    return ans;
}

void solve() {
    int n;
    cin >> n >> MOD;
    vector<int> fact(3 * n + 1, 1);
    for (int i = 2; i <= 3 * n; i++) fact[i] = fact[i - 1] * i % MOD;
    vector<int> fact_inv(3 * n + 1, 1);
    for (int i = 2; i <= 3 * n; i++) fact_inv[i] = binexp(fact[i]);

    int s0 = 1;
    // 1 step
    int s1 = (2 * fact[2 * n] % MOD - fact[n] - s0 + 2 * MOD) % MOD;
    int ans = s1;

    // 2 steps
    int s2 = 2 * fact[2 * n] % MOD;
    s2 *= fact[n], s2 %= MOD;
    s2 *= comb(2 * n, n, fact, fact_inv), s2 %= MOD;
    for (int i = 0; i <= n; i++) {
        int ncr = comb(n, i, fact, fact_inv);
        int c = (ncr * ncr % MOD) * ncr % MOD;
        c *= fact[n], c %= MOD;
        c *= fact[n + i], c %= MOD;
        c *= fact[n - i], c %= MOD;
        s2 = (s2 - c + MOD) % MOD;
    }
    s2 = (s2 - s1 - s0 + 2 * MOD) % MOD;
    ans += s2 * 2 % MOD, ans %= MOD;

    // 3 steps
    int s3 = (fact[3 * n] - s0 - s1 - s2 + 3 * MOD) % MOD;
    ans += s3 * 3 % MOD, ans %= MOD;
    // cout << s1 << ' ' << s2 << ' ' << s3 << '\n';

    cout << ans << '\n';
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}