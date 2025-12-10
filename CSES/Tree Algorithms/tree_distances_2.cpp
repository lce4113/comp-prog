// CSES Tree Algorithms: Tree Distances II

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> adj;
vector<int> sub, ans, dep;
int n;

int dfs(int v, int p) {
    for (auto c : adj[v]) {
        if (c == p) continue;
        dep[c] = dep[v] + 1;
        sub[v] += dfs(c, v);
    }
    return sub[v];
}

void dfs2(int v, int p) {
    ans[v] = ans[p] - sub[v] + n - sub[v];
    for (auto c : adj[v]) {
        if (c == p) continue;
        dfs2(c, v);
    }
}

int32_t main() {
    cin >> n;
    adj.assign(n, {});
    sub.assign(n, 1);
    ans.assign(n, 0);
    dep.assign(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    ans[0] = reduce(dep.begin(), dep.end());
    for (auto x : adj[0]) dfs2(x, 0);
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}