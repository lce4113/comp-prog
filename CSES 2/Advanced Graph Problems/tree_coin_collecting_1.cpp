// CSES Advanced Graph Problems: Tree Coin Collecting I

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5, B = 20;
vector<vector<int>> mn_dst(B + 1, vector<int>(MAXN, -1));
vector<vector<int>> jump(B + 1, vector<int>(MAXN, -1));
vector<vector<int>> adj(MAXN);
vector<int> tin(MAXN), tout(MAXN);
int timer = 0;

void dfs(int v, int p) {
    tin[v] = timer++;
    jump[0][v] = p;
    for (auto to : adj[v]) {
        if (to == p) continue;
        dfs(to, v);
    }
    tout[v] = timer++;
}

bool anc(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }

int lca(int u, int v) {
    if (anc(u, v)) return u;
    for (int i = B; i >= 0; i--) {
        if (!anc(jump[i][u], v)) u = jump[i][u];
    }
    return jump[0][u];
}

int D(int a, int b) {
    if (a == b) return 0;
    int ans = 0;
    for (int i = B; i >= 0; i--) {
        if (!anc(jump[i][b], a)) b = jump[i][b], ans += (1 << i);
    }
    return ans + 1;
}

int M(int a, int b) {
    if (a == b) return mn_dst[0][b];
    int ans = 1e9;
    for (int i = B; i >= 0; i--) {
        if (!anc(jump[i][b], a)) ans = min(ans, mn_dst[i][b]), b = jump[i][b];
    }
    return min(ans, mn_dst[1][b]);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<int> coin(n);
    for (auto &x : coin) cin >> x;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        if (coin[i] == 1) {
            Q.push(i);
            mn_dst[0][i] = 0;
        }
    }
    dfs(0, 0);
    while (Q.size()) {
        auto v = Q.front();
        Q.pop();
        for (auto to : adj[v]) {
            if (mn_dst[0][to] != -1) continue;
            mn_dst[0][to] = mn_dst[0][v] + 1;
            Q.push(to);
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << i << ' ' << mn_dst[0][i] << '\n';
    // }
    for (int i = 1; i <= B; i++) {
        for (int j = 0; j < n; j++) {
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
            mn_dst[i][j] = min(mn_dst[i - 1][j], mn_dst[i - 1][jump[i - 1][j]]);
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int L = lca(u, v);
        int m1 = min(M(L, u), M(L, v)), d1 = D(L, u) + D(L, v);
        cout << 2 * m1 + d1 << '\n';
    }
}