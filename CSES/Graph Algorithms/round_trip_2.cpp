// CSES Graph Algorithms: Round Trip II

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXM = 2e5;

bool vis[MAXN], path_vis[MAXN];
vector<int> adj[MAXN];
vector<int> path;

void dfs(int r) {
    path.push_back(r);
    path_vis[r] = 1, vis[r] = 1;
    for (auto c : adj[r]) {
        if (path_vis[c]) {
            auto it = find(path.begin(), path.end(), c);
            cout << path.end() - it + 1 << '\n';
            for (; it != path.end(); it++) cout << *it + 1 << ' ';
            cout << c + 1 << '\n';
            exit(0);
        }
        if (vis[c]) continue;
        dfs(c);
    }
    path_vis[r] = 0;
    path.pop_back();
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < MAXN; i++) vis[i] = 0, path_vis[i] = 0;

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs(i);
    }
    cout << "IMPOSSIBLE\n";
}
