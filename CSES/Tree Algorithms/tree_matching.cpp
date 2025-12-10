// CSES Tree Algorithms: Tree Matching

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<vector<int>> adj;

pair<int, int> dfs(int v, int p) {
    vector<pair<int, int>> mts;
    int ans = 0, ready = 0, diff = 1e9;
    for (auto c : adj[v]) {
        if (c == p) continue;
        auto [m0, m1] = dfs(c, v);
        diff = min(diff, m1 - m0);
        if (m0 > m1) ready = 1;
        ans += max(m0, m1);
    }
    if (ready == 1) return {ans, ans + 1};
    return {ans, ans - diff + 1};
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    adj.assign(n, {});
    n--;
    while (n--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto ans = dfs(0, 0);
    cout << max(ans.f, ans.s) << '\n';
}