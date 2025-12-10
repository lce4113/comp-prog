// CSES Tree Algorithms: Fixed-Length Paths II

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5;
vector<int> adj[MAXN];
bool rem[MAXN];
int subtree[MAXN];
int cnt[MAXN + 1];
int pfs[MAXN + 2];
int mxd = 0;

int ans = 0;
int n, k1, k2;

int subs(int v, int p) {
    subtree[v] = 1;
    for (auto to : adj[v]) {
        if (to == p || rem[to]) continue;
        subtree[v] += subs(to, v);
    }
    return subtree[v];
}

int find(int v, int p, int goal) {
    for (auto to : adj[v]) {
        if (rem[to] || to == p) continue;
        if (subtree[to] >= goal) return find(to, v, goal);
    }
    return v;
}

void add(int v, int p, int d) {
    if (d > k2) return;
    if (k1 - d <= mxd) ans += pfs[min(mxd, k2 - d + 1)] - pfs[max(0ll, k1 - d)];
    cnt[d]++;
    for (auto to : adj[v]) {
        if (rem[to] || to == p) continue;
        add(to, v, d + 1);
    }
}

void decomp(int v) {
    int tot = subs(v, -1);
    int centroid = find(v, -1, tot / 2);
    rem[centroid] = 1;
    // config cnt & pfs
    for (int i = 1; cnt[i]; i++) cnt[i] = 0;
    cnt[0] = 1, mxd = 1;
    for (int i = 0; i < mxd; i++) {
        pfs[i + 1] = pfs[i] + cnt[i];
    }
    for (auto to : adj[centroid]) {
        if (rem[to]) continue;
        add(to, -1, 1);
        // config pfs
        while (cnt[mxd]) mxd++;
        for (int i = 0; i < mxd; i++) {
            pfs[i + 1] = pfs[i] + cnt[i];
        }
    }
    for (auto to : adj[centroid]) {
        if (rem[to]) continue;
        decomp(to);
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k1 >> k2;
    memset(rem, 0, sizeof(rem));
    memset(subtree, 0, sizeof(subtree));
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    decomp(0);
    cout << ans << '\n';
}