// ASC 1: Problem B

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<vector<int>> g;
vector<int> p;
int n, m;

int bfs() {
    queue<pair<int, int>> Q;
    Q.push({n, INF});
    p[n] = n;
    while (Q.size()) {
        auto [v, mn] = Q.front();
        Q.pop();
        // cout << v << ' ' << mn << '\n';
        if (v == n + 1) return mn;
        for (int to = 0; to < n + 2; to++) {
            if (g[v][to] == 0) continue;
            if (p[to] != -1) continue;
            p[to] = v;
            Q.push({to, min(mn, g[v][to])});
        }
    }
    return 0;
}

int max_flow() {
    p.assign(n + 2, -1);
    int f, res = 0;
    while (f = bfs()) {
        int cur = n + 1;
        while (cur != n) {
            g[p[cur]][cur] -= f;
            g[cur][p[cur]] += f;
            cur = p[cur];
        }
        res += f;
        p.assign(n + 2, -1);
    }
    // cout << "res: " << res << '\n';
    return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef ONLINE_JUDGE
    ifstream cin("cooling.in");
    ofstream cout("cooling.out");
#endif

    cin >> n >> m;
    g.assign(n + 2, vector<int>(n + 2));
    int tot = 0;
    vector<array<int, 4>> es(m);
    for (auto &x : es) {
        for (auto &y : x) cin >> y;
    }
    for (auto &[u, v, lo, hi] : es) {
        u--, v--;
        tot += lo;
        g[u][v] = hi - lo;
        g[n][v] += lo, g[u][n + 1] += lo;
    }
    // for (int i = 0; i < n + 2; i++) {
    //     for (int j = 0; j < n + 2; j++) {
    //         cout << "edge " << i << ' ' << j << ": " << g[i][j] << '\n';
    //     }
    // }
    if (max_flow() < tot) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (auto [u, v, lo, hi] : es) {
        cout << lo + g[v][u] << '\n';
    }
}