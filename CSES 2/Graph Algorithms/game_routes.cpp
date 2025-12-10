// CSES Graph Algorithms: Game Routes

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> dp;

int dfs(int c) {
    if (vis[c]) return dp[c];
    vis[c] = 1;
    for (auto x : adj[c]) dp[c] += dfs(x), dp[c] %= MOD;
    return dp[c];
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    adj.assign(n, {}), vis.assign(n, 0), dp.assign(n, 0);
    dp[n - 1] = 1;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    cout << dfs(0) << '\n';
}
