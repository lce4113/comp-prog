// CSES Graph Algorithms: Download Speed

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<set<int>> adj;
vector<vector<int>> capacity;
vector<int> ps;

int bfs(int s, int t) {
    for (auto &x : ps) x = -1;
    ps[s] = -2;
    queue<pair<int, int>> Q;
    Q.push({s, 1e18});
    while (Q.size()) {
        auto [c, flow] = Q.front();
        Q.pop();
        for (auto x : adj[c]) {
            if (capacity[c][x] == 0) continue;
            if (ps[x] != -1) continue;
            ps[x] = c;
            int new_flow = min(flow, capacity[c][x]);
            // cout << x << ' ' << flow << '\n';
            if (x == t) return new_flow;
            Q.push({x, new_flow});
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int cflow, res = 0;
    ps.assign(n, -1);
    // cout << bfs(s, t) << '\n';
    // for (auto x : ps) cout << x << ' ';
    // cout << '\n';
    while ((cflow = bfs(s, t))) {
        int c = t;
        while (c != s) {
            capacity[c][ps[c]] += cflow;
            capacity[ps[c]][c] -= cflow;
            c = ps[c];
        }
        res += cflow;
        // cout << cflow << '\n';
        // cout << '\n';
    }
    return res;
}

void solve() {
    cin >> n >> m;
    adj.assign(n, {}), capacity.assign(n, vector<int>(n, 0));
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].insert(b);
        adj[b].insert(a);
        capacity[a][b] += c;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (auto x : adj[i]) cout << x << ' ';
    //     cout << '\n';
    // }

    cout << max_flow(0, n - 1) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}