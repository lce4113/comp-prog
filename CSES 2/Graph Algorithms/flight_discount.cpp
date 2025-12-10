// CSES Graph Algorithms: Flight Discount

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(2 * n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[u].push_back({v + n, w / 2});
        adj[u + n].push_back({v + n, w});
    }

    vector<int> dst(2 * n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    Q.push({0, 0});
    dst[0] = 0;
    while (Q.size()) {
        auto [d, c] = Q.top();
        Q.pop();
        if (d > dst[c]) continue;
        for (auto [x, w] : adj[c]) {
            if (d + w < dst[x]) {
                dst[x] = d + w;
                Q.push({dst[x], x});
            }
        }
    }
    cout << dst.back() << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}