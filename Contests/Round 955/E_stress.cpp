// Codeforces Round 955: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

map<pair<int, int>, int> dp;

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
        b /= 2;
    }
    return res;
}

int p2(int n, int k) {
    if (n == 0) return 0;
    if (k == 0) return 1;
    if (dp.count({n, k})) return dp[{n, k}];
    if (k >= log2(n)) {
        n %= MOD;
        int ans = (n * (n + 1)) % MOD;
        ans *= binexp(2), ans %= MOD;
        dp[{n, k}] = ans;
        return ans;
    }
    if (k == log2(n) - 1) {
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
    // cout << "off: " << n << ' ' << k << '\n';
    if (k >= (int)log2(n)) {
        n %= MOD;
        int ans = (n * (n + 1)) % MOD;
        ans *= binexp(2), ans %= MOD;
        return ans;
    }
    if (n == 0) return 0;
    if (k == 0) return 1;
    int p = (1 << (int)log2(n));
    return (p2(p, k) + off(n - p, k - 1)) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;
    // cout << n << " " << k << " = ";
    // cout << off(n, k) << '\n';
}

int ch(int n, int k) {
    int c = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (__builtin_popcount(i) <= k) {
            c++;
        } else {
            c %= MOD;
            ans += (c * (c + 1) % MOD) * binexp(2) % MOD;
            c = 0;
        }
    }
    c %= MOD;
    ans += c * (c + 1) / 2, ans %= MOD;
    return ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t = 1;
    // cin >> t;
    // while (t--) solve();

    // for (int n = 1e7; n <= 1e7; n++) {
    //     for (int k = 20; k <= 20; k++) {
    int n = 2e7 + 1, k = 20;
    cout << n << ' ' << k << ' ' << ch(n, k) << ' ' << off(n, k) << '\n';
    if (ch(n, k) != off(n, k)) {
        cout << "ohno\n";
        return 0;
    }
    //     }
    // }
}