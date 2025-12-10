// CSES Graph Algorithms: Police Chase

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 500, INF = 1e18;

vector<vector<int>> g(MAXN, vector<int>(MAXN));
vector<int> p;
int n, m;

int bfs() {
    queue<pair<int, int>> Q;
    Q.emplace(0, INF);
    while (Q.size()) {
        auto [v, mn] = Q.front();
        Q.pop();
        if (v == n - 1) return mn;
        for (int to = 0; to < n; to++) {
            if (g[v][to] == 0) continue;
            if (p[to] != -1) continue;
            Q.emplace(to, min(g[v][to], mn));
            p[to] = v;
        }
    }
    return 0;
}

int max_flow() {
    p.assign(n, -1);
    int flow = 0, res = 0;
    while (flow = bfs()) {
        int c = n - 1;
        while (c != 0) {
            g[p[c]][c] -= flow;
            g[c][p[c]] += flow;
            c = p[c];
        }
        p.assign(n, -1);
        res += flow;
    }
    return res;
}

int32_t main() {
    cin >> n >> m;
    vector<pair<int, int>> es;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u][v] = 1;
        g[v][u] = 1;
        es.emplace_back(u, v);
    }
    cout << max_flow() << '\n';

    vector<bool> st(n);
    queue<int> Q;
    Q.push(0), st[0] = 1;
    while (Q.size()) {
        auto v = Q.front();
        Q.pop();
        for (int to = 0; to < n; to++) {
            if (st[to]) continue;
            if (g[v][to]) Q.push(to), st[to] = 1;
        }
    }

    vector<pair<int, int>> ans;
    for (auto e : es) {
        if (st[e.f] != st[e.s]) ans.push_back(e);
    }

    for (auto x : ans) cout << x.f + 1 << ' ' << x.s + 1 << '\n';
}