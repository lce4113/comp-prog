// CSES Mathematics: Distributing Apples

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 2e6;

vector<int> f(MAXN + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int32_t main() {
    for (int i = 1; i <= MAXN; i++) f[i] = f[i - 1] * i, f[i] %= MOD;
    int a, b;
    cin >> a >> b;
    int ans = f[a + b - 1];
    ans *= binexp(f[a - 1]), ans %= MOD;
    ans *= binexp(f[b]), ans %= MOD;
    cout << ans << '\n';
}