// CSES Mathematics: Binomial Coefficients

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

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = f[a];
    ans *= rf[b], ans %= MOD;
    ans *= rf[a - b], ans %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) f[i] = f[i - 1] * i, f[i] %= MOD;
    for (int i = 1; i <= MAXN; i++) rf[i] = binexp(f[i]);

    int t = 1;
    cin >> t;
    while (t--) solve();
}