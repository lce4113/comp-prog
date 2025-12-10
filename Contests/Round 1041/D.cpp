// Codeforces Round 1041: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 1e6;
const int MOD = 1e9 + 7;
vector<int> f(MAXN + 1, 1);

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (m + 1 != n) {
        cout << "0\n";
        return;
    }
    int ans = 2, path = 0;
    for (int v = 0; v < n; v++) {
        int deg = 0, lf = 0;
        for (auto to : adj[v]) {
            if (adj[to].size() != 1)
                deg++;
            else
                lf++;
        }
        if (deg > 2) {
            cout << "0\n";
            return;
        }
        if (adj[v].size() != 1) path++;
        ans *= f[lf], ans %= MOD;
    }
    if (path > 1) ans *= 2, ans %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) f[i] = f[i - 1] * i % MOD;

    int t = 1;
    cin >> t;
    while (t--) solve();
}