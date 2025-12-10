// CSES Graph Algorithms: Teleporters Path

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
vector<vector<int>> g(MAXN + 1);
vector<int> ans;

void fail() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

void rec(int v) {
    while (g[v].size()) {
        auto to = g[v].back();
        g[v].pop_back();
        rec(to);
    }
    ans.push_back(v);
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int> in(n + 1), out(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        in[v]++, out[u]++;
        g[v].push_back(u);
    }
    in[1]++, out[n]++;

    for (int i = 1; i <= n; i++) {
        if (in[i] != out[i]) fail();
    }

    rec(n);
    if (ans.size() != m + 1) fail();

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}