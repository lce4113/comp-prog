// CSES Tree Algorithms: Distance Queries

#include <bits/stdc++.h>
using namespace std;

const int MAXB = 20;
vector<int> tin, tout, dep;
vector<vector<int>> adj;
vector<vector<int>> bin;
int timer = 0;

void dfs(int v, int p) {
    dep[v] = dep[p] + 1;
    bin[0][v] = p;
    tin[v] = timer++;
    for (auto c : adj[v]) {
        if (c == p) continue;
        dfs(c, v);
    }
    tout[v] = timer++;
}

bool anc(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }

int lca(int u, int v) {
    if (anc(u, v)) return u;
    for (int i = MAXB; i >= 0; i--) {
        if (!anc(bin[i][u], v)) u = bin[i][u];
    }
    return bin[0][u];
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    tin.assign(n, 0);
    tout.assign(n, 0);
    dep.assign(n, -1);
    adj.assign(n, {});
    bin.assign(MAXB + 1, vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, 0);

    for (int i = 1; i <= MAXB; i++) {
        for (int j = 0; j < n; j++) bin[i][j] = bin[i - 1][bin[i - 1][j]];
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int L = lca(u, v);
        cout << dep[u] + dep[v] - 2 * dep[L] << '\n';
    }
}