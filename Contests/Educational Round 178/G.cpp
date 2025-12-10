// Codeforces Educational Round 178: Problem G

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct DSU {
    vector<int> sz, p;
    vector<bool> par;
    vector<array<int, 7>> hist;
    int n, os = 0, cs;
    DSU(int n) : sz(n, 1), p(n), par(n, 0), n(n), cs(n) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    pair<int, bool> root(int x) {
        int c = 0;
        while (p[x] != x) {
            c ^= par[x];
            x = p[x];
        }
        return {x, c};
    }
    void u(int x, int y) {
        auto [rx, xp] = root(x);
        auto [ry, yp] = root(y);
        if (sz[rx] < sz[ry]) swap(rx, ry), swap(xp, yp);
        hist.push_back({ry, p[ry], par[ry], rx, sz[rx], os, cs});
        if (rx == ry) {
            if (xp == yp) os++;
            return;
        }
        cs--;
        par[ry] = xp ^ yp ^ 1;
        p[ry] = rx;
        sz[rx] += sz[ry];
    }
    int snap() { return hist.size(); }
    void rollback(int until) {
        while (snap() > until) {
            // cout << "x ";
            auto [ry, pry, parry, rx, szrx, osp, csp] = hist.back();
            hist.pop_back();
            p[ry] = pry;
            par[ry] = parry;
            sz[rx] = szrx;
            os = osp, cs = csp;
        }
    }
};

struct QTree {
    DSU d;
    vector<vector<pair<int, int>>> a;
    vector<bool> ans;
    int q;
    QTree(int n, int q) : d(n), a(2 * q), ans(q), q(q) {}
    void u(int l, int r, int u, int v) {
        for (l += q, r += q; l < r; l /= 2, r /= 2) {
            if (l % 2) a[l++].push_back({u, v});
            if (r % 2) a[--r].push_back({u, v});
        }
    }
    void dfs(int i = 1) {
        if (i >= 2 * q) return;
        int snap = d.snap();

        for (auto [x, y] : a[i]) d.u(x, y);
        if (i >= q) {
            int even = d.cs - d.os;
            ans[i - q] = (d.n - even) % 2;
        }
        dfs(i * 2), dfs(i * 2 + 1);

        d.rollback(snap);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(n);
    for (auto &x : a) {
        cin >> x.f;
        x.f--, x.s = 0;
    }

    QTree qt(n, q);
    vector<int> qs(q);
    for (int i = 0; i < q; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        x--, y--, qs[i] = k % 3;
        qt.u(a[x].s, i, x, a[x].f);
        a[x] = {y, i};
    }
    for (int i = 0; i < n; i++) {
        qt.u(a[i].s, q, i, a[i].f);
    }
    qt.dfs();
    for (int i = 0; i < q; i++) {
        if (qs[i] == 0) {
            cout << 0 << '\n';
        } else if (qs[i] == 1) {
            cout << 1 << '\n';
        } else {
            cout << (qt.ans[i] ? 2 : 1) << '\n';
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}