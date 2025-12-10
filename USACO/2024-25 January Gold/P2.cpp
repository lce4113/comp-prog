// USACO 2024-25 January Gold
// Problem 2. "Reachable Pairs"

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU {
    vector<int> ps, sz;
    DSU(int n) : ps(n), sz(n, 1) {
        for (int i = 0; i < n; i++) ps[i] = i;
    }
    int f(int x) { return x == ps[x] ? x : (ps[x] = f(ps[x])); }
    int cs(int x) { return sz[f(x)]; }
    void u(int x, int y) {
        int xr = f(x), yr = f(y);
        if (xr == yr) return;
        if (sz[xr] < sz[yr]) swap(xr, yr);
        ps[yr] = xr;
        sz[xr] += sz[yr];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    string t;
    cin >> t;
    vector<set<int>> adj(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (auto x : adj[i]) cout << x << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    for (int i = 0; i < n; i++) {
        if (t[i] == '0') continue;
        if (adj[i].size() == 0) continue;
        int mx = *adj[i].rbegin();
        if (mx < i) continue;
        // cout << i << ' ' << mx << '\n';
        for (auto x : adj[i]) {
            if (x == mx) continue;
            adj[x].erase(i);
            adj[x].insert(mx);
            adj[mx].insert(x);
        }
        adj[i].clear();
        adj[i].insert(mx);
        adj[mx].insert(i);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (auto x : adj[i]) cout << x << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    DSU d(n);
    vector<long long> ans(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = ans[i + 1];
        set<int> nc;
        for (auto x : adj[i]) {
            if (x < i) continue;
            nc.insert(d.f(x));
        }
        for (auto x : nc) {
            ans[i] -= d.cs(x) * (d.cs(x) - 1) / 2;
            d.u(i, x);
        }
        ans[i] += d.cs(i) * (d.cs(i) - 1) / 2;
    }

    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
