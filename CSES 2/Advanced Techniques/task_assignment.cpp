// CSES Advanced Techniques: Task Assignment

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int N = 200;
const int V = 2 * N + 2;

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
            int val = dst + e[3] + pi[e[0]] - pi[e[1]];
            if (val < d[e[1]] && e[2]) {
                d[e[1]] = val;
                p[e[1]] = to;
                Q.push({val, e[1]});
            }
        }
    }
    for (int i = 0; i < V; i++) pi[i] = min(INF, pi[i] + d[i]);
}

void max_flow(int s, int t) {
    while (1) {
        p.assign(V, -1);
        d.assign(V, INF);
        path(s);
        // for (auto x : p) cout << x << ' ';
        // cout << '\n';
        if (p[t] == -1) return;
        int c = t;
        // cout << "path: ";
        while (c != s) {
            auto e = edges[p[c]];
            edges[p[c]][2]--;
            edges[p[c] ^ 1][2]++;
            c = e[0];
            // cout << c << ' ';
        }
        // cout << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    for (auto &x : cost) {
        for (auto &y : x) cin >> y;
    }
    for (int i = 0; i < n; i++) {
        edges.push_back({2 * n, i, 1, 0});
        edges.push_back({i, 2 * n, 0, 0});
        edges.push_back({2 * n + 1, i + n, 0, 0});
        edges.push_back({i + n, 2 * n + 1, 1, 0});
        for (int j = 0; j < n; j++) {
            edges.push_back({i, j + n, 1, cost[i][j]});
            edges.push_back({j + n, i, 0, -cost[i][j]});
        }
    }
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(i);
    }

    max_flow(2 * n, 2 * n + 1);
    vector<pair<int, int>> ans;
    int tot_cost = 0;
    for (auto e : edges) {
        if (e[0] < n && e[1] >= n && e[1] < 2 * n && e[2] == 0) {
            tot_cost += cost[e[0]][e[1] - n];
            ans.push_back({e[0], e[1] - n});
        }
    }
    cout << tot_cost << '\n';
    for (auto x : ans) cout << x.first + 1 << ' ' << x.second + 1 << '\n';
}