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

int n = 3, m;
vector<pair<int, int>> req;

int ch() {
    int ans = 0;
    vector<int> rs(3 * n);
    set<int> remst;
    for (int i = 1; i <= 3 * n; i++) remst.insert(i);
    for (auto x : req) remst.erase(x.s), rs[x.f] = x.s;
    vector<int> rem;
    for (auto x : remst) rem.push_back(x);
    do {
        auto p = rs;
        for (int i = 0, j = 0; i < (int)rem.size(); j++) {
            if (p[j] == 0) p[j] = rem[i++];
        }
        // for (auto x : p) cout << x << ' ';
        // cout << '\n';
        // for (auto x : rem) cout << x << ' ';
        // cout << '\n';
        vector<int> ms;
        for (int i = 0; i < 3; i++) {
            vector<int> c;
            for (int j = 0; j < 3; j++) c.push_back(p[i * 3 + j]);
            sort(c.begin(), c.end());
            ms.push_back(c[1]);
        }
        sort(ms.begin(), ms.end());
        ans += ms[1] == 5;
    } while (next_permutation(rem.begin(), rem.end()));
    return ans;
}

int solve() {
    vector<pair<int, int>> fixed(3, {0, 0});
    int mid = (3 * n + 1) / 2;
    int mf = -1;
    int remg = mid - 1, reml = mid - 1;
    for (auto &x : req) {
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
            cout << c << '\n';
            ans += c, ans %= MOD;
        }
        return ans;
    }
    int ans = 1;
    int rem = 2 * n;
    for (int i = 0; i < 3; i++) rem -= fixed[i].f + fixed[i].s;
    rem += fixed[mf].f + fixed[mf].s;
    int gs = (n - 1) / 2 - fixed[mf].s;
    int ls = (n - 1) / 2 - fixed[mf].f;
    // for (auto x : fixed) cout << x.f << ' ' << x.s << '\n';
    // cout << gs << ' ' << ls << '\n';
    if (gs < 0 || ls < 0) return 0;
    if (remg < gs || reml < ls) return 0;
    ans *= comb(remg, gs), ans %= MOD;
    ans *= comb(reml, ls), ans %= MOD;
    ans *= f[gs + ls], ans %= MOD;
    ans *= f[rem], ans %= MOD;
    return ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= MAXN; i++) f[i] = f[i - 1] * i % MOD;
    for (int i = 2; i <= MAXN; i++) rf[i] = binexp(f[i]);

    m = 5;
    // req = {{8, 1}, {7, 2}, {1, 3}, {2, 4}, {5, 9}};

    // cout << solve() << ' ' << ch() << '\n';
    auto rng = default_random_engine{};
    vector<int> ps(3 * n), ns(3 * n);
    for (int j = 0; j < 3 * n; j++) ps[j] = j, ns[j] = j + 1;
    for (int i = 0; i < 1e3; i++) {
        req.clear();
        shuffle(begin(ps), end(ps), rng);
        shuffle(begin(ns), end(ns), rng);
        // for (auto x : ps) cout << x << ' ';
        // cout << '\n';
        for (int k = 0; k < m; k++) {
            req.push_back({ps[k], ns[k]});
        }
        for (auto x : req) cout << x.f << ' ' << x.s << '\n';
        int a1 = solve(), a2 = ch();
        cout << "ans: " << a1 << ' ' << a2 << '\n';
        if (a1 != a2) {
            cout << "ohno\n";
            return 0;
        }
    }
}