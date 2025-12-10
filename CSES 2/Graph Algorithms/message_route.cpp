// CSES Graph Algorithms: Message Route

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
    queue<int> Q;
    vector<int> p(n, -1);
    Q.push(0);
    while (Q.size()) {
        auto c = Q.front();
        Q.pop();
        for (auto x : adj[c]) {
            if (p[x] != -1) continue;
            Q.push(x);
            p[x] = c;
        }
    }
    if (p[n - 1] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<int> ans(1, n);
    int c = n - 1;
    while (c != 0) c = p[c], ans.push_back(c + 1);
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}