// Codeforces Round 1033: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;
const int MAXN = 1e5;

vector<int> fact(MAXN + 1), factr(MAXN + 1);

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; a *= a, a %= MOD, b /= 2)
        if (b % 2) res *= a, res %= MOD;
    return res;
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    int n = (a - 1) * k + 1;
    n %= MOD;
    int ans = 1;
    for (int i = n; i > n - a; i--) ans *= i, ans %= MOD;
    for (int i = 1; i <= a; i++) ans *= binexp(i), ans %= MOD;
    ans *= k, ans %= MOD;
    ans *= b - 1, ans %= MOD;
    ans += 1, ans %= MOD;
    cout << n << ' ' << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        factr[i] = binexp(fact[i]);
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}