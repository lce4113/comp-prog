// CSES Graph Algorithms: Road Construction

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;
    DSU(int n) : n(n), par(n), sz(n, 1) {
        for (int i = 0; i < n; i++) par[i] = i;
    }
    int root(int x) { return x == par[x] ? x : root(par[x]); }
    void unite(int x, int y) {
        int x_root = root(x), y_root = root(y);
        if (x_root == y_root) return;
        // if (sz[x_root] < sz[y_root]) swap(x_root, y_root);
        par[y_root] = x_root;
        sz[x_root] += sz[y_root];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    DSU d(n);
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        d.unite(u, v);
        for (int i = 0; i < n; i++) cout << d.root(i) << ' ';
        cout << '\n';
    }
}
