// CSES Additional Problems II: Grid Puzzle I

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 50;
const int V = 2 * MAXN + 2;
vector<vector<int>> capacity(V, vector<int>(V));
vector<int> p, vis;
int n;

void bfs(int s) {
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    while (Q.size()) {
        auto v = Q.front();
        Q.pop();
        for (int to = 0; to < V; to++) {
            if (capacity[v][to] == 0) continue;
            if (vis[to]) continue;
            vis[to] = 1;
            Q.push(to);
            p[to] = v;
        }
    }
}

int max_flow(int s, int t) {
    int tot = 0;
    while (1) {
        p.assign(V, -1);
        vis.assign(V, 0);
        bfs(s);
        if (p[t] == -1) break;
        int c = t;
        int flow = 1e18;
        while (c != s) {
            flow = min(flow, capacity[p[c]][c]);
            c = p[c];
        }
        tot += flow;
        c = t;
        while (c != s) {
            capacity[p[c]][c] -= flow;
            capacity[c][p[c]] += flow;
            c = p[c];
        }
    }
    return tot;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    int x;
    int tot = 0, tot2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        tot += x;
        capacity[2 * n][i] = x;
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        tot2 += x;
        capacity[i + n][2 * n + 1] = x;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            capacity[i][j + n] = 1;
        }
    }
    int flow = max_flow(2 * n, 2 * n + 1);
    if (flow != tot || tot != tot2) {
        cout << "-1\n";
        return 0;
    }
    vector<string> ans(n, string(n, '.'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (capacity[j + n][i]) ans[i][j] = 'X';
        }
    }
    for (auto x : ans) cout << x << '\n';
}