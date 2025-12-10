// CSES Graph Algorithms: Planets and Kingdoms

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;

vector<int> kingdom(MAXN), ordered;
vector<vector<int>> adj(MAXN), adjr(MAXN);
vector<bool> vis(MAXN);

void order(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (auto to : adj[v]) order(to);
    ordered.push_back(v);
}

void dfs(int v, int k) {
    if (kingdom[v]) return;
    kingdom[v] = k;
    for (auto to : adjr[v]) dfs(to, k);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        order(i);
    }
    reverse(ordered.begin(), ordered.end());

    int k = 0;
    for (auto r : ordered) {
        if (kingdom[r]) continue;
        k++;
        dfs(r, k);
    }

    cout << k << '\n';
    for (int i = 0; i < n; i++) cout << kingdom[i] << ' ';
    cout << '\n';
}
