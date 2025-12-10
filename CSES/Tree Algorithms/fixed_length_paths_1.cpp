// CSES Tree Algorithms: Fixed-Length Paths I

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5 + 1;
vector<int> adj[MAXN];
int cnt[MAXN + 1];
bool rem[MAXN];
int subtree[MAXN];
vector<int> tmp;

int ans = 0;
int n, k;

int subs(int v, int p) {
    subtree[v] = 1;
    for (auto to : adj[v]) {
        if (rem[to] || to == p) continue;
        subtree[v] += subs(to, v);
    }
    return subtree[v];
}

int find(int v, int p, int req) {
    for (auto to : adj[v]) {
        if (rem[to] || to == p || subtree[to] < req) continue;
        return find(to, v, req);
    }
    return v;
}

void add(int v, int p, int d) {
    if (d > k) return;
    ans += cnt[k - d], tmp.push_back(d);
    for (auto to : adj[v]) {
        if (rem[to] || to == p) continue;
        add(to, v, d + 1);
    }
}

void decomp(int v) {
    int centroid = find(v, -1, subs(v, -1) / 2);
    rem[centroid] = 1;
    for (int i = 1; cnt[i]; i++) cnt[i] = 0;
    for (auto to : adj[centroid]) {
        if (!rem[to]) {
            add(to, centroid, 1);
            for (auto d : tmp) cnt[d]++;
            tmp.clear();
        }
    }
    for (auto to : adj[centroid]) {
        if (!rem[to]) decomp(to);
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    memset(cnt, 0, sizeof(cnt));
    memset(rem, 0, sizeof(rem));
    cnt[0] = 1;
    cin >> n >> k;
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