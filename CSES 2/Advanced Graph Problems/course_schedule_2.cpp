// CSES Advanced Graph Problems: Course Schedule II

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<vector<int>> adj(MAXN);
vector<int> out(MAXN);

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
        out[u]++;
    }
    vector<int> ans;
    priority_queue<int> Q;
    for (int i = 0; i < n; i++)
        if (out[i] == 0) Q.push(i);
    while (Q.size()) {
        auto v = Q.top();
        Q.pop();
        ans.push_back(v);
        for (auto to : adj[v]) {
            out[to]--;
            if (out[to] == 0) Q.push(to);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x + 1 << ' ';
    cout << '\n';
}