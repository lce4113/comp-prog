// CSES Additional Problems II: Coin Grid

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;
vector<vector<int>> adj(MAXN);
vector<set<int>> adj2(MAXN);

vector<int> mt, vis;

bool try_kuhn(int v) {
    if (vis[v]) return 0;
    vis[v] = 1;
    for (auto to : adj[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to])) {
            mt[to] = v;
            return 1;
        }
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '.') continue;
            adj[i].push_back(j);
            adj2[j + n].insert(i);
        }
    }

    mt.assign(n, -1);
    for (int i = 0; i < n; i++) {
        vis.assign(n, 0);
        try_kuhn(i);
    }

    set<int> alt;
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        if (mt[i] == -1) {
            Q.push(i + n);
            alt.insert(i + n);
            continue;
        }
        adj2[i + n].erase(mt[i]);
        adj2[mt[i]].insert(i + n);
    }

    while (Q.size()) {
        auto v = Q.front();
        Q.pop();
        for (auto to : adj2[v]) {
            if (alt.count(to)) continue;
            alt.insert(to);
            Q.push(to);
        }
    }

    for (int i = n; i < 2 * n; i++) {
        if (alt.count(i))
            alt.erase(i);
        else
            alt.insert(i);
    }

    cout << alt.size() << '\n';
    for (auto x : alt) {
        if (x < n) {
            cout << 1 << ' ' << x + 1 << '\n';
        } else {
            cout << 2 << ' ' << x - n + 1 << '\n';
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}