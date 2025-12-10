// Codeforces Round 1045: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> vis(n);
    queue<int> Q;
    Q.push(0);
    vis[0] = 1;
    int d1, d2;
    while (Q.size()) {
        auto v = Q.front();
        Q.pop();
        d1 = v;
        for (auto to : g[v]) {
            if (!vis[to]) {
                Q.push(to);
                vis[to] = 1;
            }
        }
    }
    vector<int> p(n, -1);
    Q.push(d1);
    p[d1] = d1;
    while (Q.size()) {
        auto v = Q.front();
        Q.pop();
        d2 = v;
        for (auto to : g[v]) {
            if (p[to] == -1) {
                Q.push(to);
                p[to] = v;
            }
        }
    }
    vector<int> diam(1, d2);
    while (diam.back() != d1) {
        diam.push_back(p[diam.back()]);
    }
    // for (auto x : diam) cout << x + 1 << ' ';
    // cout << '\n';

    for (int i = 1; i < n - 1; i++) {
        for (auto to : g[diam[i]]) {
            if (to != diam[i - 1] && to != diam[i + 1]) {
                cout << diam[i - 1] + 1 << ' ' << diam[i] + 1 << ' ' << to + 1
                     << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}