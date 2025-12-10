// CSES Tree Algorithms: Counting Paths

#include <bits/stdc++.h>
using namespace std;

const int MAXB = 20;

vector<int> tin, tout, in_val, out_val, sub;
vector<vector<int>> adj;
vector<vector<int>> bin;
int timer = 0, tot = 0;

void euler(int v, int p) {
    bin[0][v] = p;
    tin[v] = timer++;
    for (auto c : adj[v]) {
        if (c == p) continue;
        euler(c, v);
    }
    tout[v] = timer++;
}

bool anc(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }

int lca(int u, int v) {
    for (int i = MAXB; i >= 0; i--) {
        if (!anc(bin[i][u], v)) u = bin[i][u];
    }
    return u;
}

void dfs(int v, int p) {
    for (auto c : adj[v]) {
        if (c == p) continue;
        dfs(c, v);
        sub[v] += sub[c] + in_val[c] + out_val[c];
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    tin.assign(n, 0);
    tout.assign(n, 0);
    sub.assign(n, 0);
    in_val.assign(n, 0);
    out_val.assign(n, 0);
    adj.assign(n, {});
    bin.assign(MAXB + 1, vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    euler(0, 0);
    for (int i = 1; i <= MAXB; i++) {
        for (int j = 0; j < n; j++) {
            bin[i][j] = bin[i - 1][bin[i - 1][j]];
        }
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (anc(v, u)) swap(u, v);
        if (anc(u, v)) {
            in_val[u]++, out_val[v]--;
            continue;
        }
        int lu = lca(u, v), l = bin[0][lu];
        in_val[lu]++, out_val[u]--;
        in_val[l]++, out_val[v]--;
    }
    dfs(0, 0);
    for (int v = 0; v < n; v++) cout << -sub[v] - out_val[v] << ' ';
    cout << '\n';
}