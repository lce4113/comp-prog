// CSES Graph Algorithms: Building Roads

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        queue<int> Q;
        Q.push(i);
        ans.push_back(i + 1);
        vis[i] = 1;
        while (Q.size()) {
            auto c = Q.front();
            Q.pop();
            for (auto x : adj[c]) {
                if (vis[x]) continue;
                Q.push(x);
                vis[x] = 1;
            }
        }
    }
    int N = ans.size();
    cout << N - 1 << '\n';
    for (int i = 0; i < N - 1; i++) {
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}