// CSES Mathematics: Bracket Sequences I

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int MAXN = 1e6;

vector<int> f(MAXN + 1, 1);
vector<int> rf(MAXN + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int32_t main() {
    for (int i = 1; i <= MAXN; i++) {
        f[i] = f[i - 1] * i, f[i] %= MOD;
        rf[i] = binexp(f[i]);
    }
    int n;
    cin >> n;
    if (n % 2) {
        cout << "0\n";
        return 0;
    }
    int c1 = f[n];
    c1 *= rf[n / 2 - 1], c1 %= MOD;
    c1 *= rf[n / 2 + 1], c1 %= MOD;
    int c2 = f[n];
    c2 *= rf[n / 2], c2 %= MOD;
    c2 *= rf[n / 2], c2 %= MOD;
    cout << (c2 - c1 + MOD) % MOD << '\n';
}