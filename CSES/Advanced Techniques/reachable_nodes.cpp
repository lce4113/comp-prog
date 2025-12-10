// CSES Advanced Techniques: Reachable Nodes

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4;

int ans[MAXN];
bitset<MAXN> rs[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];

void reach(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    rs[v].set(v);
    for (auto to : adj[v]) {
        reach(to);
        rs[v] |= rs[to];
    }
    ans[v] = rs[v].count();
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        reach(i);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
}