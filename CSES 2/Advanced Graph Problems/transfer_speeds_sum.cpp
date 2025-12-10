// CSES Advanced Graph Problems: Transfer Speeds Sum

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU {
    int n;
    vector<int> p, sz;
    DSU(int _n) : n(_n), p(_n), sz(_n, 1) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int root(int x) { return x == p[x] ? x : (p[x] = root(p[x])); }
    void u(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        sz[rx] += sz[ry];
        p[ry] = rx;
    }
    int cmp(int x) { return sz[root(x)]; }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    DSU D(n);
    vector<array<int, 3>> es;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        es.push_back({w, u, v});
    }
    sort(es.rbegin(), es.rend());
    int ans = 0;
    for (auto e : es) {
        ans += D.cmp(e[1]) * D.cmp(e[2]) * e[0];
        D.u(e[1], e[2]);
    }
    cout << ans << '\n';
}