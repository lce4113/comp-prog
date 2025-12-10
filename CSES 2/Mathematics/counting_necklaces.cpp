// CSES Mathematics: Counting Necklaces

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += binexp(m, gcd(i, n)), ans %= MOD;
    }
    ans *= binexp(n), ans %= MOD;
    cout << ans << '\n';
}