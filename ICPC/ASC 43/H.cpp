// ASC 43: Problem H

#include <bits/stdc++.h>
using namespace std;

#define int long long

using vi = vector<int>;
#define sz(V) (int)V.size()
#define all(V) V.begin(), V.end()
#define rep(i, l, r) for (int i = l; i < r; i++)

template <class T>
T edmondsKarp(vector<unordered_map<int, T>> &graph, int source, int sink) {
    assert(source != sink);
    T flow = 0;
    vi par(sz(graph)), q = par;
    for (;;) {
        fill(all(par), -1);
        par[source] = 0;
        int ptr = 1;
        q[0] = source;
        rep(i, 0, ptr) {
            int x = q[i];
            for (auto e : graph[x]) {
                if (par[e.first] == -1 && e.second > 0) {
                    par[e.first] = x;
                    q[ptr++] = e.first;
                    if (e.first == sink) goto out;
                }
            }
        }
        return flow;
    out:
        T inc = numeric_limits<T>::max();
        for (int y = sink; y != source; y = par[y]) {
            inc = min(inc, graph[par[y]][y]);
        }
        flow += inc;
        for (int y = sink; y != source; y = par[y]) {
            int p = par[y];
            if ((graph[p][y] -= inc) <= 0) graph[p].erase(y);
            graph[y][p] += inc;
        }
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    ifstream cin("hentium.in");
    ofstream cout("hentium.out");

    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<unordered_map<int, int>> g(n + 2);
        int x, y;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            g[n][i] = x;
            g[i][n + 1] = y;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> x;
                g[i][j] = x;
                g[j][i] = x;
            }
        }
        int flow = edmondsKarp(g, n, n + 1);
        vector<int> ans(n, 1);
        queue<int> Q;
        Q.push(n);
        while (Q.size()) {
            auto v = Q.front();
            Q.pop();
            for (auto [to, w] : g[v]) {
                if (w == 0) continue;
                if (to == n || ans[to] == 2) continue;
                ans[to] = 2;
                Q.push(to);
            }
        }
        cout << flow << '\n';
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }
}