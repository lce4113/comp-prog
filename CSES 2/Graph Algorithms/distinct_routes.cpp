// CSES Graph Algorithms: Distinct Routes

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500, INF = 1e9;

vector<vector<int>> g(MAXN, vector<int>(MAXN));
vector<vector<int>> adj(MAXN), adj2(MAXN);
vector<int> p(MAXN, -1);
int n, m;

int bfs() {
    queue<pair<int, int>> Q;
    Q.emplace(0, INF);
    while (Q.size()) {
        auto [v, mn] = Q.front();
        Q.pop();
        if (v == n - 1) return mn;
        for (auto to : adj[v]) {
            if (g[v][to] == 0) continue;
            if (p[to] != -1) continue;
            Q.emplace(to, min(mn, g[v][to]));
            p[to] = v;
        }
    }
    return 0;
}

int max_flow() {
    int flow, res = 0;
    while (flow = bfs()) {
        int c = n - 1;
        while (c != 0) {
            g[p[c]][c] -= flow;
            g[c][p[c]] += flow;
            c = p[c];
        }
        res += flow;
        p.assign(MAXN, -1);
    }
    return res;
}

int32_t main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u][v] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
        adj2[u].push_back(v);
    }

    int flow = max_flow();

    cout << flow << '\n';
    for (int i = 0; i < flow; i++) {
        int v = 0;
        vector<int> ans(1, v);
        while (v != n - 1) {
            for (auto to : adj2[v]) {
                if (g[to][v]) {
                    g[to][v] = 0;
                    v = to;
                    ans.push_back(v);
                    break;
                }
            }
        }
        cout << ans.size() << '\n';
        for (auto x : ans) cout << x + 1 << ' ';
        cout << '\n';
    }
}