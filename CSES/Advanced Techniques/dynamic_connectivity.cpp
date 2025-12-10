// CSES Advanced Techniques: Dynamic Connectivity

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

struct DSU {
    int n, cs;
    vector<int> p, sz;
    vector<array<int, 4>> hist;
    DSU(int _n) : n(_n), cs(_n), p(_n), sz(_n, 1) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int root(int x) { return x == p[x] ? x : root(p[x]); }
    void u(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        hist.push_back({ry, rx, sz[rx], cs});
        p[ry] = rx;
        sz[rx] += sz[ry];
        cs--;
    }
    int snap() { return hist.size(); }
    void roll(int snap) {
        while (hist.size() > snap) {
            auto [_ry, _rx, _szrx, _cs] = hist.back();
            hist.pop_back();
            p[_ry] = _ry;
            sz[_rx] = _szrx;
            cs = _cs;
        }
    }
};

struct QTree {
    int n, qs;
    vector<vector<pair<int, int>>> tree;
    vector<int> ans;
    DSU D;
    QTree(int _n, int _qs) : n(_n), qs(_qs), tree(2 * _qs), ans(_qs), D(_n) {}
    void q(int u, int v, int l, int r) {
        for (l += qs, r += qs; l < r; l /= 2, r /= 2) {
            if (l % 2) tree[l++].push_back({u, v});
            if (r % 2) tree[--r].push_back({u, v});
        }
    }
    void dfs(int i = 1) {
        if (i >= 2 * qs) return;
        int snap = D.snap();

        for (auto [a, b] : tree[i]) D.u(a, b);
        if (i >= qs) ans[i - qs] = D.cs;
        dfs(2 * i);
        dfs(2 * i + 1);

        D.roll(snap);
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;

    QTree Q(n, m + q);
    map<pair<int, int>, int> mp;
    int i = 0;
    for (; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
        mp[{u, v}] = i;
    }
    for (; i < m + q; i++) {
        int tp, u, v;
        cin >> tp >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
        if (tp == 1) {
            mp[{u, v}] = i;
        } else {
            Q.q(u, v, mp[{u, v}], i);
            mp.erase({u, v});
        }
    }
    for (auto [e, st] : mp) {
        Q.q(e.f, e.s, st, m + q);
    }
    Q.dfs();
    for (int i = m - 1; i < m + q; i++) cout << Q.ans[i] << ' ';
    cout << '\n';
}