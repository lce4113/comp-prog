// CSES Tree Algorithms: Company Queries II

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXB = 20;

vector<int> tin, tout;
int timer = 0;
vector<vector<int>> adj;
vector<vector<int>> bin;

void dfs(int v) {
    tin[v] = timer++;
    for (auto c : adj[v]) dfs(c);
    tout[v] = timer++;
}

bool anc(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }

int lca(int u, int v) {
    if (anc(u, v)) return u;
    for (int i = MAXB; i >= 0; i--) {
        if (!anc(bin[i][u], v)) u = bin[i][u];
    }
    return bin[0][u];
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    tin.assign(n, 0);
    tout.assign(n, 0);
    adj.assign(n, {});
    bin.assign(MAXB + 1, vector<int>(n));
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
        bin[0][i] = x;
    }

    dfs(0);

    for (int i = 1; i <= MAXB; i++) {
        for (int j = 0; j < n; j++) {
            bin[i][j] = bin[i - 1][bin[i - 1][j]];
        }
    }

    while (q--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cout << lca(u, v) + 1 << '\n';
    }
}