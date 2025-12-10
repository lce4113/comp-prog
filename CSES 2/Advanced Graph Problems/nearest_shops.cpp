// CSES Advanced Graph Problems: Nearest Shops

#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << ": " << x + 1 << '\n';

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;
    queue<int> Q;
    vector<int> dist(n, -1), dist2(n, 1e9), root(n, -1);
    while (k--) {
        int x;
        cin >> x;
        x--;
        dist[x] = 0, root[x] = x, Q.push(x);
    }
    vector<vector<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while (Q.size()) {
        auto v = Q.front();
        Q.pop();
        for (auto to : adj[v]) {
            if (dist[to] != -1) {
                int r1 = root[v], r2 = root[to];
                if (r1 != r2) {
                    int nd = dist[v] + dist[to] + 1;
                    // debug(r1);
                    // debug(r2);
                    // debug(v);
                    // debug(to);
                    // debug(nd - 1);
                    // cout << '\n';
                    dist2[r1] = min(dist2[r1], nd);
                    dist2[r2] = min(dist2[r2], nd);
                }
                continue;
            }
            dist[to] = dist[v] + 1;
            root[to] = root[v];
            Q.push(to);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << (dist[i] == 0 ? (dist2[i] == 1e9 ? -1 : dist2[i]) : dist[i])
             << ' ';
    }
    cout << '\n';
}