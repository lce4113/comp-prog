// Spring 2025 Columbia University Local Contest
// Problem I

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i) up[v][i] = up[up[v][i - 1]][i - 1];

    for (int u : adj[v]) {
        if (u != p) dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int dist(int anc, int u) {
    if (anc == u) return 0;
    int res = 0;
    for (int i = l; i >= 0; --i) {
        if (tin[anc] < tin[up[u][i]]) u = up[u][i], res += (1 << i);
    }
    return res + 1;
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1, -1));
    dfs(root, root);
}

void solve() {
    int k;
    cin >> n >> k;
    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    preprocess(0);

    vector<int> u(k), v(k);
    for (auto &x : u) cin >> x;
    for (auto &x : v) cin >> x;

    int ans = 0;
    for (int i = 0; i < k; i++) {
        u[i]--, v[i]--;
        int anc = lca(u[i], v[i]);
        int d1 = dist(anc, v[i]), d2 = dist(anc, u[i]);
        ans += d1 + d2;
        cout << d1 << ' ' << d2 << ' ' << anc << ' ' << u[i] << ' ' << v[i]
             << '\n';
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}