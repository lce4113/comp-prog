// CSES Graph Algorithms: Flight Routes

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int INF = 1e18;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[v].push_back({u, w});
    }

    vector<int> dst(n, INF);
    vector<pair<int, int>> p(n, {-1, -1});
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    Q.push({0, n - 1});
    dst[n - 1] = 0;
    while (Q.size()) {
        auto [d, r] = Q.top();
        Q.pop();
        if (d != dst[r]) continue;
        for (auto [c, w] : adj[r]) {
            if (d + w < dst[c]) {
                dst[c] = d + w;
                p[c] = {r, w};
                Q.push({dst[c], c});
            }
        }
    }

    vector<vector<pair<int, int>>> sides(n);
    for (int r = 0; r < n; r++) {
        for (auto [c, w] : adj[r]) {
            if (p[c] == make_pair(r, w)) {
                p[c] = {r, -1};
                continue;
            }
            sides[c].push_back({r, w + dst[r] - dst[c]});
        }
    }

    Q.push({dst[0], 0});
    for (int i = 0; i < k; i++) {
        auto [d, r] = Q.top();
        Q.pop();
        cout << d << ' ';
        while (r != -1) {
            for (auto [c, side] : sides[r]) {
                Q.push({d + side, c});
            }
            r = p[r].f;
        }
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}