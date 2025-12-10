// CSES Tree Algorithms: Tree Diameter

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> dst(n, -1);
    vector<bool> vis(n, 0);
    n--;
    while (n--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int d1 = 0;
    queue<int> Q;
    Q.push(0);
    vis[0] = 1;
    while (Q.size()) {
        auto v = Q.front();
        Q.pop();
        d1 = v;
        for (auto c : adj[v]) {
            if (vis[c]) continue;
            vis[c] = 1;
            Q.push(c);
        }
    }
    Q.push(d1);
    dst[d1] = 0;
    while (Q.size()) {
        auto v = Q.front();
        Q.pop();
        for (auto c : adj[v]) {
            if (dst[c] != -1) continue;
            dst[c] = dst[v] + 1;
            Q.push(c);
        }
    }
    cout << *max_element(dst.begin(), dst.end()) << '\n';
}