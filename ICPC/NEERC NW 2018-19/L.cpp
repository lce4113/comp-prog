// NEERC NW 2018-19: Problem L

#include <bits/stdc++.h>
using namespace std;

const int B = 42;

array<int, 3> b(int x) {
    array<int, 3> res;
    for (int i = 0; i < 3; i++) res[i] = x % B, x /= B;
    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> in(n);
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back({v, i});
        in[v]++;
    }
    queue<int> Q;
    for (int i = 0; i < n; i++)
        if (in[i] == 0) Q.push(i);
    int c = 0;
    vector<int> topo(n);
    while (Q.size()) {
        int v = Q.front();
        Q.pop();
        topo[v] = c++;
        for (auto [to, _] : g[v]) {
            in[to]--;
            if (in[to] == 0) {
                Q.push(to);
            }
        }
    }
    vector<char> ans(m);
    for (int v = 0; v < n; v++) {
        for (auto [to, i] : g[v]) {
            array<int, 3> x = b(topo[v]), y = b(topo[to]);
            // cout << v << ' ' << to << '\n';
            // cout << topo[v] << ' ' << topo[to] << '\n';
            // for (auto z : x) cout << z << ' ';
            // cout << '\n';
            // for (auto z : y) cout << z << ' ';
            // cout << '\n';
            if (x[2] < y[2]) {
                ans[i] = 'R';
            } else if (x[1] < y[1]) {
                ans[i] = 'G';
            } else {
                ans[i] = 'B';
            }
        }
    }
    for (auto x : ans) cout << x << '\n';
}