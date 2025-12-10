// CSES Advanced Techniques: Necessary Roads

#include <bits/stdc++.h>
using namespace std;

vector<int> low, num;
vector<pair<int, int>> ans;
vector<bool> vis;
vector<vector<int>> adj;
int timer = 0;

void dfs(int v, int p) {
    if (vis[v]) return;
    vis[v] = 1;
    num[v] = low[v] = timer++;
    for (auto to : adj[v]) {
        if (to == p) continue;
        dfs(to, v);
        low[v] = min(low[v], low[to]);
        if (low[to] > num[v]) ans.emplace_back(v + 1, to + 1);
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    num.assign(n, 0);
    low.assign(n, 0);
    vis.assign(n, 0);
    adj.assign(n, {});
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);

    cout << ans.size() << '\n';
    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}