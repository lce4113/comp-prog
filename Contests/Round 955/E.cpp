// Codeforces Round 955: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

map<pair<int, int>, int> dp;

int sp2(int n) {
    int x = 1;
    while (2 * x <= n) x <<= 1;
    return x;
}

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
        b /= 2;
    }
    return res;
}

int binexp2(int a, int b) {
    int res = 1;
    for (; b; a *= a) {
        if (b % 2) res *= a;
        b /= 2;
    }
    return res;
}

int p2(int n, int k) {
    if (dp.count({n, k})) return dp[{n, k}];
    if (n == 0) return 0;
    if (k == 0) return 1;
    if ((1ll << k) >= sp2(n)) {
        n %= MOD;
        int ans = (n * (n + 1)) % MOD;
        ans *= binexp(2), ans %= MOD;
        dp[{n, k}] = ans;
        return ans;
    }
    if ((1ll << k) == sp2(n) * 2) {
        n %= MOD;
        int ans = (n * (n - 1)) % MOD;
        ans *= binexp(2), ans %= MOD;
        dp[{n, k}] = ans;
        return ans;
    }
    int ans = (p2(n / 2, k) + p2(n / 2, k - 1)) % MOD;
    // cout << "p2: " << n << ' ' << k << " = " << ans << '\n';
    dp[{n, k}] = ans;
    return ans;
}

int off(int n, int k) {
    if (n == 0) return 0;
    if (k == 0) return 1;
    if ((1ll << k) >= sp2(n)) {
        n %= MOD;
        int ans = (n * (n + 1)) % MOD;
        ans *= binexp(2), ans %= MOD;
        return ans;
    }
    int p = sp2(n);
    // int p = binexp(2, log2(n));
    int ans = (p2(p, k) + off(n - p, k - 1)) % MOD;
    // cout << "off: " << n << ' ' << k << " = " << ans << '\n';
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    // cout << (1ll << (int)log(n)) << '\n';
    cout << off(n, k) << '\n';
    // int x = 0;
    // n = 10;
    // cout << (1ll << (int)__lg(n)) << '\n';
    // while (n) n /= 2, x++;
    // cout << (1ll << x) << '\n';
    // cout << binexp2(2, x) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // cout << binexp(2) << '\n';

    int t = 1;
    cin >> t;
    while (t--) solve();
}