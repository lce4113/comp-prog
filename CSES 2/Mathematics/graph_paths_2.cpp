// CSES Mathematics: Graph Paths II

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 2e18;
int n, m;

vector<vector<int>> mat_mul(vector<vector<int>> &A, vector<vector<int>> &B) {
    vector<vector<int>> res(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] = min(res[i][j], A[i][k] + B[k][j]);
            }
        }
    }
    return res;
}

int32_t main() {
    int k;
    cin >> n >> m >> k;
    vector<vector<int>> adj(n, vector<int>(n, INF));
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        adj[u][v] = min(adj[u][v], c);
    }
    vector<vector<int>> res(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) res[i][i] = 0;
    for (; k; k /= 2, adj = mat_mul(adj, adj)) {
        if (k % 2) res = mat_mul(res, adj);
    }
    cout << (res[0][n - 1] == INF ? -1 : res[0][n - 1]) << '\n';
}