// CSES Tree Algorithms: Distinct Colors

#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<vector<int>> adj;
vector<int> vals;

set<int> dfs(int v, int p) {
    set<int> st({vals[v]});
    for (auto to : adj[v]) {
        if (to == p) continue;
        auto child_st = dfs(to, v);
        if (child_st.size() > st.size()) swap(st, child_st);
        st.merge(child_st);
    }
    ans[v] = st.size();
    return st;
}

int32_t main() {
    int n;
    cin >> n;
    ans.assign(n, 0);
    adj.assign(n, {});
    vals.assign(n, 0);
    for (auto &x : vals) cin >> x;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}