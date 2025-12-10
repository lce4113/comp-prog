// CSES Advanced Techniques: New Roads Queries

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int B = 20;

struct DSU {
    int n;
    vector<int> p, sz;
    DSU(int _n) : n(_n), p(_n), sz(_n, 1) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int root(int x) { return x == p[x] ? x : (p[x] = root(p[x])); }
    bool same(int x, int y) { return root(x) == root(y); }
    void u(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        p[ry] = rx;
        sz[rx] += sz[ry];
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> es(m);
    for (auto &x : es) {
        cin >> x.f >> x.s;
        x.f--, x.s--;
    }
    vector<pair<int, int>> qs(q);
    for (auto &x : qs) {
        cin >> x.f >> x.s;
        x.f--, x.s--;
    }
    vector<pair<int, int>> lr(q);
    for (int i = 0; i < q; i++) {
        lr[i] = {-1, m};
        if (qs[i].f == qs[i].s) lr[i] = {-2, -1};
    }
    while (B--) {
        vector<vector<int>> ms(m);
        for (int i = 0; i < q; i++) {
            if (lr[i].s - lr[i].f == 1) continue;
            ms[(lr[i].f + lr[i].s) / 2].push_back(i);
        }
        DSU D(n);
        for (int i = 0; i < m; i++) {
            D.u(es[i].f, es[i].s);
            for (auto num : ms[i]) {
                if (D.same(qs[num].f, qs[num].s)) {
                    lr[num].s = i;
                } else {
                    lr[num].f = i;
                }
            }
        }
    }
    for (auto x : lr) cout << (x.s == m ? -1 : x.s + 1) << '\n';
}