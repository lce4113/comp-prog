// CSES Graph Algorithms: Flight Routes Check

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n), adjr(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }

    vector<bool> vis(n, 0);
    queue<int> Q;
    Q.push(0);
    vis[0] = 1;
    while (Q.size()) {
        auto r = Q.front();
        Q.pop();
        for (auto c : adj[r]) {
            if (vis[c]) continue;
            Q.push(c);
            vis[c] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << "NO\n" << 1 << ' ' << i + 1 << '\n';
            return 0;
        }
    }

    vis.clear();
    vis.assign(n, 0);
    Q.push(0);
    vis[0] = 1;
    while (Q.size()) {
        auto r = Q.front();
        Q.pop();
        for (auto c : adjr[r]) {
            if (vis[c]) continue;
            Q.push(c);
            vis[c] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << "NO\n" << i + 1 << ' ' << 1 << '\n';
            return 0;
        }
    }

    cout << "YES\n";
}
