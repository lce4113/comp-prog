// Codeforces Round 1051: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, bool>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--, v--;
        adj[u].push_back({v, a > b});
        adj[v].push_back({u, a > b});
    }
    int l = -1, r = 1;
    vector<int> ans(n);
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    ans[0] = 0;
    while (Q.size()) {
        auto [v, p] = Q.front();
        Q.pop();
        for (auto [to, sw] : adj[v]) {
            if (to == p) continue;
            if (sw) {
                ans[to] = to < v ? r++ : l--;
            } else {
                ans[to] = to < v ? l-- : r++;
            }
            Q.push({to, v});
        }
    }
    for (auto x : ans) cout << x - l << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}