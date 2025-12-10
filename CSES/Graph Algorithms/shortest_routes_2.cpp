// CSES Graph Algorithms: Shortest Routes II

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> dist(n, vector<int>(n, INF));
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // for (auto x : dist) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << (dist[u][v] == INF ? -1 : dist[u][v]) << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}