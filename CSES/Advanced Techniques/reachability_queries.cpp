// CSES Advanced Techniques: Reachability Queries

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4;
bitset<MAXN> rs[MAXN];
vector<int> adj[MAXN], adjr[MAXN];
set<int> adj2[MAXN];
vector<bool> vis(MAXN);
vector<int> order, scc(MAXN, -1);

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (auto to : adj[v]) dfs(to);
    order.push_back(v);
}

void dfs2(int v, int k) {
    if (scc[v] != -1) return;
    scc[v] = k;
    for (auto to : adjr[v]) dfs2(to, k);
}

void reach(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    rs[v][v] = 1;
    for (auto to : adj2[v]) {
        reach(to);
        rs[v] |= rs[to];
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs(i);
    }
    reverse(order.begin(), order.end());
    int c = 0;
    for (auto v : order) {
        if (scc[v] != -1) continue;
        dfs2(v, c++);
    }

    for (int v = 0; v < n; v++) {
        for (auto to : adj[v]) {
            adj2[scc[v]].insert(scc[to]);
        }
    }

    vis.assign(MAXN, 0);
    for (int i = 0; i < c; i++) {
        if (vis[i]) continue;
        reach(i);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << (rs[scc[a]][scc[b]] ? "YES\n" : "NO\n");
    }
}