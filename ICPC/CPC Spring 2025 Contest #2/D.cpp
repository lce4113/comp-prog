// Spring 2025 Columbia University Local Contest
// Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, m, k;
vector<vector<pair<int, int>>> adj;

int sumds(int r) {
    set<pair<int, int>> Q;
    vector<int> ds(n + m, 1e18);
    Q.insert({r, 0});
    ds[r] = 0;
    while (Q.size()) {
        auto [c, cd] = *Q.begin();
        Q.erase(Q.begin());
        for (auto [x, d] : adj[c]) {
            if (cd + d < ds[x]) {
                Q.erase({x, ds[x]});
                ds[x] = cd + d;
                Q.insert({x, ds[x]});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i] == 1e18) return -1;
        ans += ds[i];
    }
    // cout << r << ' ' << ans << '\n';
    return ans;
}

void solve() {
    cin >> n >> m >> k;
    adj.assign(n + m, vector<pair<int, int>>());
    while (k--) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    int ans = -1, ansr;
    for (int i = n; i < n + m; i++) {
        int c = sumds(i);
        if (c == -1) continue;
        if (c < ans || ans == -1) ans = c, ansr = i;
    }
    if (ans == -1) {
        cout << "-1\n";
        return;
    }
    cout << ansr << ' ' << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}