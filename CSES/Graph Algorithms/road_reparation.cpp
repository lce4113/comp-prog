// CSES Graph Algorithms: Road Reparation

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int INF = 1e18;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<bool> vis(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    Q.emplace(0, 0);
    int ans = 0, num = 0;
    while (Q.size()) {
        auto [d, r] = Q.top();
        Q.pop();
        if (vis[r]) continue;
        vis[r] = 1;
        ans += d, num++;
        for (auto [c, w] : adj[r]) {
            if (vis[c]) continue;
            Q.emplace(w, c);
        }
    }

    if (num != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << ans << '\n';
}
