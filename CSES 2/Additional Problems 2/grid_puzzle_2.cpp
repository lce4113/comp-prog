// CSES Additional Problem II: Grid Puzzle II

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 50;
const int V = 2 * MAXN + 2;
const int INF = 1e18;
vector<vector<int>> adj(V);
// from, to, cap, cost
vector<array<int, 4>> edges;
vector<int> p, d;
vector<int> pi(V);

void path(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    Q.push({0, s});
    d[s] = 0;
    while (Q.size()) {
        auto [dst, v] = Q.top();
        Q.pop();
        if (dst != d[v]) continue;
        for (auto to : adj[v]) {
            auto e = edges[to];
            int val = dst + e[3] + pi[v] - pi[e[1]];
            if (e[2] && val < d[e[1]]) {
                d[e[1]] = val;
                p[e[1]] = to;
                Q.push({d[e[1]], e[1]});
            }
        }
    }
    for (int i = 0; i < V; i++) pi[i] = min(pi[i] + d[i], INF);
}

void setpi(int s) {
    pi.assign(V, INF);
    pi[s] = 0;
    for (int r = V; r--;) {
        for (auto e : edges) {
            if (e[2] && pi[e[0]] + e[3] < pi[e[1]]) {
                pi[e[1]] = pi[e[0]] + e[3];
            }
        }
    }
}

int max_flow(int s, int t) {
    setpi(s);
    int tot = 0;
    while (1) {
        p.assign(V, -1);
        d.assign(V, INF);
        path(s);
        if (p[t] == -1) break;
        int flow = INF;
        int c = t;
        while (c != s) {
            auto e = edges[p[c]];
            flow = min(flow, e[2]);
            c = e[0];
        }
        tot += flow;
        c = t;
        while (c != s) {
            auto e = edges[p[c]];
            edges[p[c]][2] -= flow;
            edges[p[c] ^ 1][2] += flow;
            c = e[0];
        }
    }
    return tot;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> row(n), col(n);
    vector<vector<int>> cost(n, vector<int>(n));
    for (auto &x : row) cin >> x;
    for (auto &x : col) cin >> x;
    for (auto &x : cost) {
        for (auto &y : x) cin >> y;
    }

    for (int i = 0; i < n; i++) {
        edges.push_back({2 * n, i, row[i], 0});
        edges.push_back({i, 2 * n, 0, 0});
        edges.push_back({i + n, 2 * n + 1, col[i], 0});
        edges.push_back({2 * n + 1, i + n, 0, 0});
        for (int j = 0; j < n; j++) {
            edges.push_back({i, j + n, 1, -cost[i][j]});
            edges.push_back({j + n, i, 0, cost[i][j]});
        }
    }

    for (int i = 0; i < edges.size(); i++) {
        auto e = edges[i];
        adj[e[0]].push_back(i);
    }
    int flow = max_flow(2 * n, 2 * n + 1);
    int rowt = reduce(row.begin(), row.end());
    int colt = reduce(col.begin(), col.end());
    if (flow != rowt || rowt != colt) {
        cout << "-1\n";
        return 0;
    }
    int tot_cost = 0;
    vector<string> ans(n, string(n, '.'));
    for (auto e : edges) {
        if (e[0] < n && n <= e[1] && e[1] < 2 * n && e[2] == 0) {
            ans[e[0]][e[1] - n] = 'X';
            tot_cost += cost[e[0]][e[1] - n];
        }
    }
    cout << tot_cost << '\n';
    for (auto x : ans) cout << x << '\n';
}