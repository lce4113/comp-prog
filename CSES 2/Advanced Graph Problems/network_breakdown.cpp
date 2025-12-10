// CSES Advanced Graph Problems: Network Breakdown

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

struct DSU {
    int cs, n;
    vector<int> p, sz;
    DSU(int _n) : cs(_n), n(_n), p(_n), sz(_n, 1) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int root(int x) { return x == p[x] ? x : (p[x] = root(p[x])); }
    void u(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        p[ry] = rx;
        sz[rx] += sz[ry];
        cs--;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;
    set<pair<int, int>> es;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        es.insert({u, v});
    }
    vector<pair<int, int>> es2;
    while (k--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        es2.push_back({u, v});
        es.erase({u, v});
        es.erase({v, u});
    }
    reverse(es2.begin(), es2.end());
    DSU D(n);
    for (auto x : es) D.u(x.f, x.s);
    vector<int> ans;
    for (auto x : es2) {
        ans.push_back(D.cs);
        D.u(x.f, x.s);
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}