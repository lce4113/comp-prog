// CSES Graph Algorithms: Giant Pizza

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;

vector<bool> vis;
vector<set<int>> adj(2 * MAXN), adjr(2 * MAXN);
vector<int> ordered, scc(2 * MAXN);

void order(int r) {
    if (vis[r]) return;
    vis[r] = 1;
    for (auto c : adj[r]) order(c);
    ordered.push_back(r);
}

void dfs(int r, int k) {
    if (vis[r]) return;
    vis[r] = 1, scc[r] = k;
    for (auto c : adjr[r]) dfs(c, k);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> m >> n;
    while (m--) {
        char p1, p2;
        int v1, v2, r1, r2;
        cin >> p1 >> v1 >> p2 >> v2;
        v1--, v2--;
        r1 = v1 + n, r2 = v2 + n;
        if (p1 == '-') swap(r1, v1);
        if (p2 == '-') swap(r2, v2);
        adj[r2].insert(v1), adj[r1].insert(v2);
        adjr[v1].insert(r2), adjr[v2].insert(r1);
    }

    vis.assign(2 * n, 0);
    for (int i = 0; i < 2 * n; i++) order(i);

    reverse(ordered.begin(), ordered.end());

    vis.assign(2 * n, 0);
    int k = 0;
    for (auto i : ordered) {
        if (vis[i]) continue;
        dfs(i, k++);
    }

    vector<char> ans(n, '+');
    for (int i = 0; i < n; i++) {
        if (scc[i] == scc[i + n]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (scc[i + n] > scc[i]) ans[i] = '-';
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}