// CSES Graph Algorithms: Hamiltonian Flights

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
    }
    vector<vector<int>> dp(1 << n, vector<int>(n));
    dp[1][0] = 1;
    for (int i = 3; i < (1 << n); i++) {
        if ((i & 1) == 0) continue;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) continue;
            for (auto k : adj[j]) {
                dp[i][j] += dp[i - (1 << j)][k];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}