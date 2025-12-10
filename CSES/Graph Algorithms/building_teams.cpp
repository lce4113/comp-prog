// CSES Graph Algorithms: Building Teams

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

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (ans[i] != 0) continue;
        queue<int> Q;
        Q.push(i);
        ans[i] = 1;
        while (Q.size()) {
            auto c = Q.front();
            Q.pop();
            for (auto x : adj[c]) {
                if (ans[x] != 0) {
                    if (ans[x] == ans[c]) {
                        cout << "IMPOSSIBLE\n";
                        return;
                    }
                    continue;
                }
                Q.push(x);
                ans[x] = 3 - ans[c];
            }
        }
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}