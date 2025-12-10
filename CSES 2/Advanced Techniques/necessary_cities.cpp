// CSES Advanced Techniques: Necessary Cities

#include <bits/stdc++.h>
using namespace std;

set<int> ans;
vector<int> num, low;
vector<bool> vis;
vector<vector<int>> adj;
int timer = 0, rs = 0;

void dfs(int v, int p) {
    vis[v] = 1;
    rs += p == 0;
    num[v] = low[v] = timer++;
    for (auto to : adj[v]) {
        if (p == to) continue;
        if (vis[to]) {
            low[v] = min(low[v], num[to]);
            continue;
        }
        dfs(to, v);
        low[v] = min(low[v], low[to]);
    }
    if (p != -1 && low[v] >= num[p]) ans.insert(p + 1);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    adj.assign(n, {});
    num.assign(n, 0);
    low.assign(n, 0);
    vis.assign(n, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);
    ans.erase(1);
    if (rs > 1) ans.insert(1);

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}