// CSES Advanced Techniques: Distinct Routes II

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int N = 500;
// from, to, cap, cost
vector<array<int, 4>> edges;
vector<vector<bool>> adj(N, vector<bool>(N));
vector<vector<int>> g(N);
vector<vector<int>> ans;
vector<int> pi(N);
int tot = 0;
int k;

vector<int> p, d;

void path(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    Q.push({0, s});
    p.assign(N, -1), d.assign(N, INF);
    d[s] = 0;
    while (Q.size()) {
        auto [dst, v] = Q.top();
        Q.pop();
        if (dst != d[v]) continue;
        for (auto i : g[v]) {
            auto e = edges[i];
            int val = d[e[0]] + e[3] + pi[e[0]] - pi[e[1]];
            if (e[2] && val < d[e[1]]) {
                d[e[1]] = val;
                p[e[1]] = i;
                Q.push({d[e[1]], e[1]});
            }
        }
    }
    for (int i = 0; i < N; i++) pi[i] = min(INF, pi[i] + d[i]);
}

void max_flow(int s, int t) {
    while (k--) {
        path(s);
        if (p[t] == -1) {
            cout << "-1\n";
            exit(0);
        }
        int c = t;
        while (c != s) {
            auto &e = edges[p[c]];
            auto &er = edges[p[c] ^ 1];
            e[2]--, er[2]++;
            c = e[0];
        }
    }
}

void bfs(int s) {
    p.assign(N, -1), d.assign(N, INF);
    queue<int> Q;
    Q.push(s);
    while (Q.size()) {
        int v = Q.front();
        Q.pop();
        for (int to = 0; to < N; to++) {
            if (adj[v][to]) {
                p[to] = v;
                Q.push(to);
            }
        }
    }
}

void find(int s, int t) {
    while (1) {
        bfs(s);
        if (p[t] == -1) break;
        int c = t;
        ans.push_back({c});
        while (c != s) {
            adj[p[c]][c] = 0;
            c = p[c];
            ans.back().push_back(c);
        }
        tot += ans.back().size() - 1;
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m >> k;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.push_back({u, v, 1, 1});
        edges.push_back({v, u, 0, -1});
    }
    for (int i = 0; i < edges.size(); i++) {
        auto e = edges[i];
        g[e[0]].push_back(i);
    }

    max_flow(0, n - 1);

    for (int i = 0; i < edges.size(); i += 2) {
        if (edges[i][2] == 0) adj[edges[i][0]][edges[i][1]] = 1;
    }

    // for (auto x : edges) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }

    // for (int v = 0; v < n; v++) {
    //     for (int to = 0; to < n; to++) {
    //         cout << v << ' ' << to << ' ' << adj[v][to] << '\n';
    //     }
    // }

    find(0, n - 1);

    cout << tot << '\n';
    for (auto &path : ans) {
        cout << path.size() << '\n';
        reverse(path.begin(), path.end());
        for (auto x : path) cout << x + 1 << ' ';
        cout << '\n';
    }
}