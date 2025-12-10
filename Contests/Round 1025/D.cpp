// Codeforces Round 1025: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int INF = 1e18;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (auto &x : a) cin >> x;
    int mo = INF, sm = 0;
    for (auto x : a) {
        if (x % 2) mo = min(mo, x);
        sm += x;
    }
    int mxe = sm, mxo = (mo == INF ? -1 : sm - mo);
    if (sm % 2) swap(mxe, mxo);

    map<pair<int, int>, vector<pair<int, int>>> adj;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[{u, 0}].push_back({v, 1});
        adj[{u, 1}].push_back({v, 0});
        adj[{v, 0}].push_back({u, 1});
        adj[{v, 1}].push_back({u, 0});
    }

    vector<array<int, 2>> d(n, {INF, INF});
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    d[0][0] = 0;
    while (Q.size()) {
        auto c = Q.front();
        Q.pop();
        for (auto x : adj[c]) {
            if (d[x.f][x.s] != INF) continue;
            d[x.f][x.s] = d[c.f][c.s] + 1;
            Q.push(x);
        }
    }

    // cout << mxe << ' ' << mxo << '\n';
    for (int i = 0; i < n; i++) {
        // cout << i << ' ' << d[i][0] << ' ' << d[i][1] << '\n';
        cout << (d[i][0] <= mxe || d[i][1] <= mxo);
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}