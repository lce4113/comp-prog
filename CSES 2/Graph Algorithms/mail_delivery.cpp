// CSES Graph Algorithms: Mail Delivery

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;

vector<int> ans;
vector<set<int>> g(MAXN + 1);

void rec(int v) {
    while (g[v].size()) {
        auto c = *g[v].begin();
        g[v].erase(g[v].begin());
        g[c].erase(v);
        rec(c);
    }
    ans.push_back(v);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }

    for (int i = 0; i < n; i++) {
        if (g[i].size() % 2) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    rec(1);

    if (ans.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}