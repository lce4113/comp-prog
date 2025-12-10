// CSES Graph Algorithms: School Dance

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 1e3 + 2, INF = 1e18;

vector<vector<int>> g(MAXN, vector<int>(MAXN));
vector<int> p;
int n, m, k;

int bfs() {
    queue<pair<int, int>> Q;
    Q.emplace(n + m, INF);
    while (Q.size()) {
        auto [v, mn] = Q.front();
        Q.pop();
        if (v == n + m + 1) return mn;
        for (int to = 0; to < MAXN; to++) {
            if (g[v][to] == 0) continue;
            if (p[to] != -1) continue;
            Q.emplace(to, min(mn, g[v][to]));
            p[to] = v;
        }
    }
    return 0;
}

int max_flow() {
    p.assign(MAXN, -1);
    int flow = 0, res = 0;
    while (flow = bfs()) {
        int c = n + m + 1;
        while (c != n + m) {
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
    cin >> n >> m >> k;
    while (k--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        v += n;
        g[u][v] = 1;
    }
    for (int i = 0; i < n; i++) g[n + m][i] = 1;
    for (int i = n; i < n + m; i++) g[i][n + m + 1] = 1;

    max_flow();

    vector<pair<int, int>> ans;
    for (int v = 0; v < n; v++) {
        for (int to = n; to < n + m; to++) {
            if (g[to][v]) ans.push_back({v, to - n});
        }
    }

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x.f + 1 << ' ' << x.s + 1 << '\n';
}