// CSES Mathematics: Counting Grids

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int binexp(int a, int b = MOD - 2) {
    b %= MOD - 1;
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int32_t main() {
    int n;
    cin >> n;
    if (n % 2) {
        int ans = 0;
        ans += binexp(2, n * n);
        ans += binexp(2, n * n / 4 + 1);
        ans += binexp(2, n * n / 2 + 1);
        ans += binexp(2, n * n / 4 + 1);
        ans *= binexp(4), ans %= MOD;
        cout << ans << '\n';
    } else {
        int ans = 0;
        ans += binexp(2, n * n);
        ans += binexp(2, n * n / 4);
        ans += binexp(2, n * n / 2);
        ans += binexp(2, n * n / 4);
        ans *= binexp(4), ans %= MOD;
        cout << ans << '\n';
    }
}