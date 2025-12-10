// CSES Graph Algorithms: Cycle Finding

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int INF = 1e18;

vector<bool> vis;
vector<set<int>> adj;

vector<int> path;

void dfs(int r) {
    for (auto c : adj[r]) {
        path.push_back(c);
        if (vis[c]) {
            auto it = find(path.begin(), path.end(), c);
            vector<int> ans(it, path.end());
            reverse(ans.begin(), ans.end());
            cout << "YES\n";
            for (auto x : ans) cout << x + 1 << ' ';
            cout << '\n';
            exit(0);
        }
        vis[c] = 1;
        dfs(c);
        vis[c] = 0;
        path.pop_back();
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    adj.assign(n, {});
    vis.assign(n, 0);
    vector<array<int, 3>> es(m);
    for (auto &x : es) {
        cin >> x[0] >> x[1] >> x[2];
        x[0]--, x[1]--;
    }

    vector<int> d(n, INF);
    d[0] = 0;
    bool ok = 0;
    for (int i = 0; i < n; i++) {
        ok = 1;
        for (auto [u, v, w] : es) {
            if (d[u] + w < d[v]) {
                ok = 0;
                d[v] = d[u] + w;
            }
        }
    }

    // for (auto x : d) cout << x << ' ';
    // cout << '\n';

    if (ok) {
        cout << "NO\n";
        return;
    }

    int r;
    for (int i = 0; i < m; i++) {
        for (auto [u, v, w] : es) {
            if (d[u] + w < d[v]) {
                adj[v].insert(u);
                r = v;
                d[v] = d[u] + w;
            }
        }
    }

    path.push_back(r);
    vis[r] = 1;
    dfs(r);
    vis[r] = 0;
    path.pop_back();
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}