// CSES Mathematics: Graph Paths I

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> adj;

vector<vector<int>> mat_mul(vector<vector<int>> &A, vector<vector<int>> &B) {
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += A[i][k] * B[k][j], res[i][j] %= MOD;
            }
        }
    }
    return res;
}

int32_t main() {
    int k;
    cin >> n >> m >> k;
    adj.assign(n, vector<int>(n));
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u][v]++;
    }
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++) res[i][i] = 1;
    for (; k; k /= 2, adj = mat_mul(adj, adj)) {
        if (k % 2) res = mat_mul(res, adj);
    }
    cout << res[0][n - 1] << '\n';
}