// MITIT Spring Invitational Qualification Round 2
// P1

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

const int MAXN = 1e6;
vector<int> f(MAXN + 1, 1), rf(MAXN + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; a *= a, a %= MOD, b /= 2) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int comb(int n, int r) {
    int res = f[n] * rf[r] % MOD;
    res *= rf[n - r], res %= MOD;
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> req(m);
    vector<pair<int, int>> fixed(3, {0, 0});
    int mid = (3 * n + 1) / 2;
    int mf = -1;
    int remg = mid - 1, reml = mid - 1;
    for (auto &x : req) {
        cin >> x.f >> x.s;
        x.f--;
        if (x.s == mid) {
            mf = x.f / n;
        } else {
            fixed[x.f / n].f += x.s < mid;
            fixed[x.f / n].s += x.s > mid;
            remg -= x.s > mid, reml -= x.s < mid;
        }
    }
    // cout << remg << ' ' << reml << '\n';
    if (mf == -1) {
        int ans = 0;
        for (mf = 0; mf < 3; mf++) {
            int c = 1;
            int rem = 2 * n;
            for (int i = 0; i < 3; i++) rem -= fixed[i].f + fixed[i].s;
            rem += fixed[mf].f + fixed[mf].s;
            int gs = (n - 1) / 2 - fixed[mf].s;
            int ls = (n - 1) / 2 - fixed[mf].f;
            if (gs < 0 || ls < 0) continue;
            if (remg < gs || reml < ls) continue;
            c *= comb(remg, gs), c %= MOD;
            c *= comb(reml, ls), c %= MOD;
            c *= f[gs + ls + 1], c %= MOD;
            c *= f[rem], c %= MOD;
            ans += c, ans %= MOD;
        }
        cout << ans << '\n';
        return;
    }
    int ans = 1;
    int rem = 2 * n;
    for (int i = 0; i < 3; i++) rem -= fixed[i].f + fixed[i].s;
    rem += fixed[mf].f + fixed[mf].s;
    int gs = (n - 1) / 2 - fixed[mf].s;
    int ls = (n - 1) / 2 - fixed[mf].f;
    // for (auto x : fixed) cout << x.f << ' ' << x.s << '\n';
    // cout << gs << ' ' << ls << '\n';
    if (gs < 0 || ls < 0 || remg < gs || reml < ls) {
        cout << "0\n";
        return;
    }
    ans *= comb(remg, gs), ans %= MOD;
    ans *= comb(reml, ls), ans %= MOD;
    ans *= f[gs + ls], ans %= MOD;
    ans *= f[rem], ans %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= MAXN; i++) f[i] = f[i - 1] * i % MOD;
    for (int i = 2; i <= MAXN; i++) rf[i] = binexp(f[i]);

    int t = 1;
    cin >> t;
    while (t--) solve();
}