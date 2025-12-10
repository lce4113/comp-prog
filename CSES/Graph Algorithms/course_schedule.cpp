// CSES Graph Algorithms: Course Schedule

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> ins(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        // cout << u << ' ' << v << '\n';
        adj[u].push_back(v);
        ins[v]++;
    }

    queue<int> Q;
    for (int i = 0; i < n; i++)
        if (ins[i] == 0) Q.push(i);
    vector<int> ans;
    while (Q.size()) {
        auto c = Q.front();
        Q.pop();
        ans.push_back(c);
        for (auto x : adj[c]) {
            ins[x]--;
            if (ins[x] == 0) Q.push(x);
        }
    }
    if (ans.size() < n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (auto x : ans) cout << x + 1 << ' ';
    cout << '\n';
}
