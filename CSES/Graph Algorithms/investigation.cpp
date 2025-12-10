// CSES Graph Algorithms: Investigation

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int INF = 1e18;
const int MOD = 1e9 + 7;

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
    }

    vector<int> dst(n, INF);
    vector<int> tot(n, 0);
    vector<pair<int, int>> lr(n, {INF, 0});
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    Q.emplace(0, 0);
    dst[0] = 0, tot[0] = 1, lr[0] = {0, 0};
    while (Q.size()) {
        auto [d, r] = Q.top();
        Q.pop();
        if (d > dst[r]) continue;
        for (auto [c, w] : adj[r]) {
            if (d + w > dst[c]) continue;
            if (d + w == dst[c]) {
                tot[c] += tot[r], tot[c] %= MOD;
                lr[c].f = min(lr[c].f, lr[r].f + 1);
                lr[c].s = max(lr[c].s, lr[r].s + 1);
            } else {
                tot[c] = tot[r];
                lr[c].f = lr[r].f + 1;
                lr[c].s = lr[r].s + 1;
                dst[c] = d + w;
                Q.emplace(dst[c], c);
            }
        }
    }

    cout << dst.back() << ' ';
    cout << tot.back() << ' ';
    cout << lr.back().f << ' ';
    cout << lr.back().s << ' ';
    cout << '\n';
}
