// CSES Graph Algorithms: Flight Routes

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }

    vector<int> vis(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    Q.emplace(0, 0);
    vector<int> ans(k);
    while (Q.size()) {
        auto [d, r] = Q.top();
        Q.pop();
        if (vis[r] == k) continue;
        if (r == n - 1) ans[vis[n - 1]] = d;
        vis[r]++;
        for (auto [c, w] : adj[r]) {
            Q.emplace(d + w, c);
        }
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}
