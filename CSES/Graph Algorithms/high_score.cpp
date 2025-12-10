// CSES Graph Algorithms: High Score

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> dist(n, -INF);
    vector<array<int, 3>> es;
    vector<vector<int>> adj1(n), adj2(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        es.push_back({u, v, w});
        adj1[v].push_back(u);
        adj2[u].push_back(v);
    }

    queue<int> Q;
    vector<int> vis1(n), vis2(n);
    Q.push(n - 1);
    vis1[n - 1] = 1;
    while (Q.size()) {
        auto r = Q.front();
        Q.pop();
        for (auto c : adj1[r]) {
            if (vis1[c]) continue;
            Q.push(c);
            vis1[c] = 1;
        }
    }
    Q.push(0);
    vis2[0] = 1;
    while (Q.size()) {
        auto r = Q.front();
        Q.pop();
        for (auto c : adj2[r]) {
            if (vis2[c]) continue;
            Q.push(c);
            vis2[c] = 1;
        }
    }

    dist[0] = 0;
    int ok = 0, i = 0;
    while (!ok) {
        ok = 1;
        for (auto [u, v, w] : es) {
            if (!vis1[v] || !vis2[v]) continue;
            if (dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
                ok = 0;
            }
        }
        if (++i == n && !ok) {
            cout << "-1\n";
            return;
        }
    }
    cout << dist[n - 1] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}