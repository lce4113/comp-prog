// CSES Graph Algorithms: Coin Collector

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5;

vector<vector<int>> adj(MAXN), adjr(MAXN);
vector<bool> vis;
vector<int> ordered;
vector<set<int>> sccs;
vector<int> scc_num(MAXN);

void order(int r) {
    if (vis[r]) return;
    vis[r] = 1;
    for (auto c : adj[r]) order(c);
    ordered.push_back(r);
}

void dfs(int r, int k) {
    if (vis[r]) return;
    vis[r] = 1;
    sccs.back().insert(r), scc_num[r] = k;
    for (auto c : adjr[r]) dfs(c, k);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for (auto &x : coins) cin >> x;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }

    vis.assign(n, 0);
    for (int i = 0; i < n; i++) order(i);
    reverse(ordered.begin(), ordered.end());
    vis.assign(n, 0);
    int k = 0;
    for (auto i : ordered) {
        if (vis[i]) continue;
        sccs.push_back({});
        dfs(i, k++);
    }

    vector<int> tots(k);
    for (int i = 0; i < k; i++) {
        for (auto x : sccs[i]) tots[i] += coins[x];
    }

    vector<int> dp = tots;
    reverse(sccs.begin(), sccs.end());
    for (auto scc : sccs) {
        for (auto r : scc) {
            for (auto c : adj[r]) {
                int sr = scc_num[r], sc = scc_num[c];
                if (sr == sc) continue;
                dp[sr] = max(dp[sr], dp[sc] + tots[sr]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';
}