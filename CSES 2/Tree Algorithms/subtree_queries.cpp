// CSES Tree Algorithms: Subtree Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) : n(_n), a(2 * _n) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = a[pos * 2] + a[pos * 2 + 1];
        }
    }
    int q(int l, int r) {
        int ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans += a[l++];
            if (r % 2) ans += a[--r];
        }
        return ans;
    }
};

vector<int> vals, tin, tout;
vector<vector<int>> adj;
int timer = 0;

void dfs(int v, int p) {
    tin[v] = timer++;
    for (auto to : adj[v]) {
        if (to == p) continue;
        dfs(to, v);
    }
    tout[v] = timer++;
}

int32_t main() {
    int n, q;
    cin >> n >> q;
    vals.assign(n, 0);
    tin.assign(n, 0);
    tout.assign(n, 0);
    adj.assign(n, {});
    for (auto &x : vals) cin >> x;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    Tree seg(timer);
    for (int i = 0; i < n; i++) seg.u(tin[i], vals[i]);
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int k, v;
            cin >> k >> v;
            k--;
            seg.u(tin[k], v);
        } else {
            int k;
            cin >> k;
            k--;
            cout << seg.q(tin[k], tout[k] + 1) << '\n';
        }
    }
}