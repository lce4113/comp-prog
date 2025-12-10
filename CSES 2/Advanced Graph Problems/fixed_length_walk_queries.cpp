// CSES Advanced Graph Problems: Fixed Length Walk Queries

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2500;
vector<int> adj[2 * MAXN];
static short reach[MAXN][2 * MAXN];

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, q;
    cin >> n >> m >> q;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].push_back(u + n);
        adj[u + n].push_back(v);
        adj[u].push_back(v + n);
        adj[v + n].push_back(u);
    }

    fill(reach[0], reach[0] + 2 * MAXN * MAXN, -1);

    for (int i = 0; i < n; i++) {
        reach[i][i] = 0;
        int Q[5000];
        int qh = 0, qt = 0;
        Q[qt++] = i;
        while (qh != qt) {
            auto v = Q[qh++];
            for (auto to : adj[v]) {
                if (reach[i][to] != -1) continue;
                reach[i][to] = reach[i][v] + 1;
                Q[qt++] = to;
            }
        }
    }

    while (q--) {
        int u, v, x;
        cin >> u >> v >> x;
        u--, v--;
        if (x & 1) v += n;
        if (reach[u][v] == -1 || reach[u][v] > x) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}