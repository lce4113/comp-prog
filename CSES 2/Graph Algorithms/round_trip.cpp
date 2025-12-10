// CSES Graph Algorithms: Round Trip

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

    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
        if (p[i] != -1) continue;
        queue<int> Q;
        Q.push(i);
        p[i] = i;
        while (Q.size()) {
            auto r = Q.front();
            Q.pop();
            for (auto c : adj[r]) {
                if (c == p[r]) continue;
                if (p[c] != -1) {
                    set<int> path({r});
                    int cur = r;
                    while (cur != i) path.insert(cur = p[cur]);
                    vector<int> ans(1, c);
                    while (!path.count(ans.back()))
                        ans.push_back(p[ans.back()]);
                    reverse(ans.begin(), ans.end());
                    ans.push_back(r);
                    while (ans.back() != ans[0]) ans.push_back(p[ans.back()]);
                    cout << ans.size() << '\n';
                    for (auto x : ans) cout << x + 1 << ' ';
                    cout << '\n';
                    return;
                }
                Q.push(c);
                p[c] = r;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}