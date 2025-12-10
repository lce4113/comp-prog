// CSES Advanced Graph Problems: MST Edge Check

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, MAXB = 20;
vector<vector<pair<int, int>>> adj(MAXN), mst(MAXN);
vector<vector<int>> jump(MAXB + 1, vector<int>(MAXN)),
    mx(MAXB + 1, vector<int>(MAXN));
vector<int> tin(MAXN), tout(MAXN);
vector<bool> vis(MAXN);
int timer = 0;

void dfs(int v, int p) {
    tin[v] = timer++;
    for (auto [to, w] : mst[v]) {
        if (to == p) continue;
        jump[0][to] = v, mx[0][to] = w;
        dfs(to, v);
    }
    tout[v] = timer++;
}

bool anc(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }

int lca(int u, int v) {
    if (u == v) return u;
    if (anc(u, v)) swap(u, v);
    for (int i = MAXB; i >= 0; i--) {
        if (!anc(jump[i][u], v)) u = jump[i][u];
    }
    return jump[0][u];
}

int M(int a, int b) {
    if (a == b) return 0;
    int M = 0;
    for (int i = MAXB; i >= 0; i--) {
        if (!anc(jump[i][b], a)) M = max(M, mx[i][b]), b = jump[i][b];
    }
    return max(M, mx[0][b]);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> es(m);
    for (auto &x : es) {
        cin >> x[0] >> x[1] >> x[2];
        x[0]--, x[1]--;
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        Q;
    Q.push({0, {-1, 0}});
    while (Q.size()) {
        auto [cw, vs] = Q.top();
        auto [p, v] = vs;
        Q.pop();
        if (vis[v]) continue;
        vis[v] = 1;
        if (p != -1) mst[v].push_back({p, cw}), mst[p].push_back({v, cw});
        for (auto [to, w] : adj[v]) Q.push({w, {v, to}});
    }
    dfs(0, 0);
    for (int i = 1; i <= MAXB; i++) {
        for (int j = 0; j < n; j++) {
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][jump[i - 1][j]]);
        }
    }

    for (auto [u, v, w] : es) {
        int L = lca(u, v);
        int cm = max(M(L, u), M(L, v));
        cout << (w <= cm ? "YES\n" : "NO\n");
    }
}