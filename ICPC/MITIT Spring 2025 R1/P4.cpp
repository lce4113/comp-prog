// MITIT Spring 2025: Problem 4

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (auto &x : a) {
        cin >> x;
        x--;
    }
    if (a[0] == 0) {
        vector<int> b;
        for (int i = 1; i < k; i++) b.push_back(a[i]);
        a = b;
        k--;
    }
    vector<set<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    // for (int i = 0; i < n; i++) {
    //     cout << i << ':';
    //     for (auto x : adj[i]) cout << x << ' ';
    //     cout << '\n';
    // }

    vector<pair<int, int>> ans;
    ans.push_back({0, a[0]});
    adj[0].insert(a[0]);
    adj[a[0]].insert(0);
    for (int i = 1; i < k; i++) {
        ans.push_back({a[i - 1], a[i]});
        adj[a[i - 1]].insert(a[i]);
        adj[a[i]].insert(a[i - 1]);
    }

    vector<int> ds(n, -1);
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    ds[0] = 0;
    while (Q.size()) {
        auto [c, d] = Q.front();
        Q.pop();
        // cout << c << ' ' << d << '\n';
        for (auto x : adj[c]) {
            // cout << x << ' ' << ds[x] << '\n';
            if (ds[x] != -1) continue;
            Q.push({x, d + 1});
            ds[x] = d + 1;
        }
    }

    for (int i = 1; i < k; i++) {
        // cout << a[i] << ' ' << ds[a[i]] << '\n';
        if (ds[a[i - 1]] >= ds[a[i]]) {
            cout << "-1\n";
            return;
        }
    }

    cout << ans.size() << '\n';
    for (auto x : ans) cout << x.f + 1 << ' ' << x.s + 1 << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
