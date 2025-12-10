// CSES Mathematics: Divisor Analysis

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7, MOD2 = 2 * (MOD - 1);

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int32_t main() {
    int n;
    cin >> n;
    int num = 1, sum = 1, tot = 1, sq = 1, tot2 = 1;
    while (n--) {
        int p, k;
        cin >> p >> k;
        num *= binexp(p, k), num %= MOD;
        sq *= binexp(p, k / 2), sq %= MOD;
        sum *= (binexp(p, k + 1) - 1 + MOD) % MOD, sum %= MOD;
        sum *= binexp((p - 1 + MOD) % MOD), sum %= MOD;
        tot *= k + 1, tot %= MOD;
        tot2 *= k + 1, tot2 %= MOD2;
    }
    // cout << num << ' ' << tot2 << '\n';
    int prod = binexp(num, (tot2 + MOD2) / 2);
    if (tot2 % 2) prod *= sq, prod %= MOD;
    cout << tot << ' ' << sum << ' ' << prod << '\n';
}