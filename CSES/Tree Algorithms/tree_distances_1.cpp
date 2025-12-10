// CSES Tree Algorithms: Tree Distances I

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

vector<int> up;
vector<vector<pair<int, int>>> down;
vector<vector<int>> adj;

void dfs(int v, int p) {
    for (auto c : adj[v]) {
        if (c == p) continue;
        dfs(c, v);
        down[v].push_back({(down[c].size() ? down[c][0].f : 0) + 1, c});
    }
    sort(down[v].rbegin(), down[v].rend());
}

void dfs2(int v, int p) {
    for (auto c : adj[v]) {
        if (c == p) continue;
        // cout << v << ' ' << c << ' ' << up[v] << '\n';
        up[c] = up[v] + 1;
        if (c == down[v][0].s) {
            if (down[v].size() != 1) up[c] = max(up[c], down[v][1].f + 1);
        } else {
            up[c] = max(up[c], down[v][0].f + 1);
        }
        dfs2(c, v);
    }
}

int32_t main() {
    int n;
    cin >> n;
    up.assign(n, 0);
    down.assign(n, {});
    adj.assign(n, {});
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    dfs2(0, 0);
    // for (int i = 0; i < n; i++)
    //     cout << (down[i].size() ? down[i][0].f : 0) << ' ';
    // cout << '\n';
    // for (auto x : up) cout << x << ' ';
    // cout << '\n';
    for (int i = 0; i < n; i++)
        cout << max(up[i], down[i].size() ? down[i][0].f : 0) << ' ';
    cout << '\n';
}