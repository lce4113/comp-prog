// CSES Advanced Graph Problems: Even Outdegree Edges

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<vector<int>> adj(MAXN);
vector<bool> vis(MAXN);

void dfs(int v, bool path) {
    if (vis[v]) return;
    vis[v] = 1;
    for (auto to : adj[v]) {
        if (to < v) dfs(to, path);
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (u < v) swap(u, v);
        deg[v]++;
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) dfs(i);
    }
}