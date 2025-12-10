// CSES Tree Algorithms: Fixed-Length Paths II

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5;

int n, k1, k2;
vector<vector<int>> adj;
int ans = 0;

void merge(deque<int> &cur, deque<int> &child) {
    int N = child.size(), M = cur.size();
    for (int d = 0; d < N - 1; d++) {
        int cnt = child[d] - child[d + 1];
        int l = k1 - d, r = k2 - d + 1;
        if (l >= M || r < 0) continue;
        if (l < 0) l = 0;
        if (r >= M) r = M - 1;
        int comp = cur[l] - cur[r];
        ans += cnt * comp;
    }
    for (int i = 0; i < N; i++) cur[i] += child[i];
}

deque<int> dfs(int v, int p) {
    deque<int> cur = {1, 0};
    for (auto to : adj[v]) {
        if (to == p) continue;
        auto child = dfs(to, v);
        child.push_front(child[0]);
        if (child.size() > cur.size()) swap(cur, child);
        merge(cur, child);
    }
    return cur;
}

int32_t main() {
    cin >> n >> k1 >> k2;
    adj.assign(n, {});
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    cout << ans << '\n';
}