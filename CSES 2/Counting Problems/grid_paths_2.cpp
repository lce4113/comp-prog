// CSES Counting Problems: Grid Paths II

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;
const int MAXN = 2e6;
vector<int> f(MAXN + 1, 1), rf(MAXN + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int comb(int a, int b) {
    int ans = f[a];
    ans *= rf[b], ans %= MOD;
    ans *= rf[a - b], ans %= MOD;
    return ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) {
        f[i] = f[i - 1] * i, f[i] %= MOD;
        rf[i] = binexp(f[i]);
    }

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (auto &x : a) cin >> x.f >> x.s;
    sort(a.begin(), a.end());
    vector<int> val(m);
    int ans = comb(2 * (n - 1), n - 1);
    for (int i = 0; i < m; i++) {
        val[i] = comb(a[i].f - 1 + a[i].s - 1, a[i].f - 1);
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (a[i].s > a[j].s) continue;
            val[j] -= val[i] *
                      comb(a[j].f - a[i].f + a[j].s - a[i].s, a[j].f - a[i].f) %
                      MOD;
            val[j] += MOD, val[j] %= MOD;
        }
        ans -= val[i] * comb(n - a[i].f + n - a[i].s, n - a[i].f) % MOD;
        ans += MOD, ans %= MOD;
    }
    cout << ans << '\n';
}