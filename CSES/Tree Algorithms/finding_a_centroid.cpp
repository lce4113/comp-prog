// CSES Tree Algorithms: Finding a Centroid

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

int dfs(int v, int p) {
    int tot = 1;
    bool ok = 1;
    for (auto to : adj[v]) {
        if (to == p) continue;
        int c = dfs(to, v);
        if (c > n / 2) ok = 0;
        tot += c;
    }
    if (ok && n - tot <= n / 2) {
        cout << v + 1 << '\n';
        exit(0);
    }
    return tot;
}

int32_t main() {
    cin >> n;
    adj.assign(n, {});
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, 0);
}