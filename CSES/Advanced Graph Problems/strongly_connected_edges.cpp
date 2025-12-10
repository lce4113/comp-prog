// CSES Advanced Graph Problems: Strong Connected Edges

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int MAXN = 1e5;
vector<vector<int>> adj(MAXN);
vector<int> num(MAXN), low(MAXN);
vector<pair<int, int>> ans;
int timer = 0;

void dfs(int v, int p) {
    if (p != -1) ans.push_back({p + 1, v + 1});
    num[v] = low[v] = ++timer;
    for (auto to : adj[v]) {
        if (to == p) continue;
        if (num[to]) {
            if (num[to] < num[v]) {
                low[v] = min(low[v], num[to]);
                ans.push_back({v + 1, to + 1});
            }
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (num[v] < low[to]) {
                cout << "IMPOSSIBLE\n";
                exit(0);
            }
        }
    }
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
        adj[v].push_back(u);
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++) {
        if (num[i] == 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (auto x : ans) cout << x.f << ' ' << x.s << '\n';
}