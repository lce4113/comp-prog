// CSES Advanced Graph Problems: Forbidden Cities

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<vector<int>> adj(MAXN);
vector<int> tin(MAXN, -1), tout(MAXN, -1), low(MAXN, -1);
vector<vector<int>> split(MAXN);
int timer = 0;

void dfs(int v, int p = -1) {
    tin[v] = low[v] = timer++;
    for (auto to : adj[v]) {
        if (to == p) continue;
        if (tin[to] != -1) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1) {
                // split[v].push_back(tin[to]);
                split[v].push_back(to);
            }
        }
    }
    tout[v] = timer++;
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
        adj[v].push_back(u);
    }
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        for (auto x : split[i]) cout << x + 1 << ' ';
        cout << '\n';
    }
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        auto i1 = upper_bound(split[c].begin(), split[c].end(), tin[a]);
        auto i2 = upper_bound(split[c].begin(), split[c].end(), tin[b]);
        cout << (i1 == i2 ? "YES\n" : "NO\n");
    }
}