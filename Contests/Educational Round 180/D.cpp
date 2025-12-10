// Codeforces Educational Round 180: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n == 2) {
        cout << "NO\n";
        return;
    }

    int r = -1;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 2) r = i;
    }
    if (r == -1) {
        cout << "NO\n";
        return;
    }

    vector<pair<int, int>> ans;
    vector<bool> vis(n);
    queue<pair<int, int>> Q;
    Q.push({r, 0});
    vis[r] = 1;
    // cout << r << '\n';
    while (Q.size()) {
        auto [c, d] = Q.front();
        Q.pop();
        for (auto x : adj[c]) {
            if (vis[x]) continue;
            vis[x] = 1;
            int d2 = x == adj[r][0] ? d + 2 : d + 1;
            if (d2 % 2) {
                ans.push_back({x, c});
            } else {
                ans.push_back({c, x});
            }
            Q.push({x, d2});
        }
    }

    cout << "YES\n";
    for (auto x : ans) cout << x.f + 1 << ' ' << x.s + 1 << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}