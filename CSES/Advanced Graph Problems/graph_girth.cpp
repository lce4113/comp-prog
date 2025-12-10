// CSES Advanced Graph Problems: Graph Girth

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2500;
vector<vector<int>> adj(MAXN);
int n, m;

int check(int i) {
    int ans = 1e9;
    vector<int> dst(n, -1);
    queue<pair<int, int>> Q;
    Q.push({i, i}), dst[i] = 0;
    while (Q.size()) {
        auto [v, p] = Q.front();
        Q.pop();
        for (auto to : adj[v]) {
            if (to == p) continue;
            if (dst[to] != -1) {
                ans = min(ans, dst[to] + dst[v] + 1);
                continue;
            }
            dst[to] = dst[v] + 1;
            Q.push({to, v});
        }
    }
    return ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        ans = min(ans, check(i));
    }
    cout << (ans == 1e9 ? -1 : ans) << '\n';
}