// CSES Counting Problems: Counting Sequence

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int MAXN = 1e6;
vector<int> f(MAXN + 1, 1), rf(MAXN + 1, 1);

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
    int n, k;
    cin >> n >> k;
    int ans = f[n];
    ans *= f[n - 1], ans %= MOD;
    ans *= rf[k - 1], ans %= MOD;
    ans *= rf[n], ans %= MOD;
    cout << ans << '\n';
}