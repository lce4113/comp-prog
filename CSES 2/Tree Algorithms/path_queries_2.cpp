// CSES Tree Algorithms: Path Queries II

#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) : n(_n), a(2 * _n, -1) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = max(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ans = -1;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans = max(ans, a[l++]);
            if (r % 2) ans = max(ans, a[--r]);
        }
        return ans;
    }
};

const int MAXN = 2e5;
vector<int> sz(MAXN);
vector<int> heavy(MAXN, -1);
vector<int> head(MAXN);
vector<int> par(MAXN);
vector<int> pos(MAXN);
vector<int> dep(MAXN, -1);
vector<int> vals(MAXN);
vector<vector<int>> adj(MAXN);
int timer = 0;
Tree seg(MAXN);

void dfs(int v, int p) {
    par[v] = p;
    sz[v] = 1;
    dep[v] = dep[p] + 1;
    for (auto to : adj[v]) {
        if (to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
        if (heavy[v] == -1 || sz[to] > sz[heavy[v]]) heavy[v] = to;
    }
}

void decomp(int v, int h) {
    pos[v] = timer++;
    seg.u(pos[v], vals[v]);
    head[v] = h;
    if (heavy[v] != -1) decomp(heavy[v], h);
    for (auto to : adj[v]) {
        if (to == par[v] || to == heavy[v]) continue;
        decomp(to, to);
    }
}

int Q(int a, int b) {
    int ans = -1;
    for (; head[a] != head[b]; a = par[head[a]]) {
        if (dep[head[a]] < dep[head[b]]) swap(a, b);
        ans = max(ans, seg.q(pos[head[a]], pos[a] + 1));
    }
    if (dep[a] < dep[b]) swap(a, b);
    ans = max(ans, seg.q(pos[b], pos[a] + 1));
    return ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> vals[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    decomp(0, 0);
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int k, v;
            cin >> k >> v;
            k--;
            vals[k] = v;
            seg.u(pos[k], v);
        } else {
            int a, b;
            cin >> a >> b;
            a--, b--;
            cout << Q(a, b) << '\n';
        }
    }
}