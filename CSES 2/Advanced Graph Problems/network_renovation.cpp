// CSES Advanced Graph Problems: Network Renovation

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<vector<int>> adj(MAXN);
vector<int> ls;

void dfs(int v, int p) {
    if (adj[v].size() == 1) ls.push_back(v + 1);
    for (auto to : adj[v]) {
        if (to == p) continue;
        dfs(to, v);
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() > 1) r = i;
    }
    dfs(r, r);
    int L = ls.size();
    cout << (L + 1) / 2 << '\n';
    for (int i = 0, j = L - 1; i < j; i++, j--)
        cout << ls[i] << ' ' << ls[j] << '\n';
    if (L % 2) cout << ls[0] << ' ' << ls[L / 2] << '\n';
}