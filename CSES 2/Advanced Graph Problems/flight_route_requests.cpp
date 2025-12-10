// CSES Advanced Graph Problems: Flight Route Requests

#include <bits/stdc++.h>
using namespace std;

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
        sz[rx] += sz[ry], sz[ry] = 1;
        p[ry] = rx;
    }
    int ans() {
        int res = 0;
        for (auto x : sz) res += x - 1;
        return res;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    DSU D(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        D.u(u, v);
    }
    cout << D.ans() << '\n';
}