#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2e5 + 5;
const int D = 19;
const int S = (1 << D);

int n, q, v[MAXN];
vector<int> adj[MAXN];

int sz[MAXN], p[MAXN][D], dep[MAXN];
int st[S], id[MAXN], tp[MAXN];

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) : n(_n), a(2 * _n, -1) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = max(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ans = -1;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans = max(ans, a[l++]);
            if (r % 2) ans = max(ans, a[--r]);
        }
        return ans;
    }
};

Tree seg(MAXN);

int dfs_sz(int cur, int par) {
    sz[cur] = 1;
    for (int chi : adj[cur]) {
        if (chi == par) continue;
        dep[chi] = dep[cur] + 1;
        p[chi][0] = cur;
        sz[cur] += dfs_sz(chi, cur);
    }
    return sz[cur];
}
void init_lca() {
    for (int d = 1; d < 18; d++)
        for (int i = 1; i <= n; i++) p[i][d] = p[p[i][d - 1]][d - 1];
}
int ct = 1;
void dfs_hld(int cur, int par, int top) {
    id[cur] = ct++;
    tp[cur] = top;
    seg.u(id[cur], v[cur]);
    int h_chi = -1, h_sz = -1;
    for (int chi : adj[cur]) {
        if (chi == par) continue;
        if (sz[chi] > h_sz) {
            h_sz = sz[chi];
            h_chi = chi;
        }
    }
    if (h_chi == -1) return;
    dfs_hld(h_chi, cur, top);
    for (int chi : adj[cur]) {
        if (chi == par || chi == h_chi) continue;
        dfs_hld(chi, cur, chi);
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int d = D - 1; d >= 0; d--) {
        if (dep[a] - (1 << d) >= dep[b]) {
            a = p[a][d];
        }
    }
    for (int d = D - 1; d >= 0; d--) {
        if (p[a][d] != p[b][d]) {
            a = p[a][d];
            b = p[b][d];
        }
    }
    if (a != b) {
        a = p[a][0];
        b = p[b][0];
    }
    return a;
}

// int path(int chi, int par) {
//     int ret = 0;
//     while (chi != par) {
//         if (tp[chi] == chi) {
//             ret = max(ret, v[chi]);
//             chi = p[chi][0];
//         } else if (dep[tp[chi]] > dep[par]) {
//             ret = max(ret, seg.q(id[tp[chi]], id[chi] + 1));
//             chi = p[tp[chi]][0];
//         } else {
//             ret = max(ret, seg.q(id[par] + 1, id[chi] + 1));
//             break;
//         }
//     }
//     return ret;
// }

int path(int a, int b) {
    int ans = -1;
    for (; tp[a] != tp[b]; a = p[tp[a]][0]) {
        if (dep[a] < dep[b]) swap(a, b);
        ans = max(ans, seg.q(id[tp[a]], id[a] + 1));
    }
    if (dep[a] < dep[b]) swap(a, b);
    ans = max(ans, seg.q(id[b], id[a] + 1));
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_sz(1, 1);
    init_lca();
    memset(st, 0, sizeof st);
    dfs_hld(1, 1, 1);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            v[s] = x;
            seg.u(id[s], v[s]);
        } else {
            int a, b;
            cin >> a >> b;
            // int c = lca(a, b);
            // int res = max(path(a, c), path(b, c));
            cout << path(a, b) << '\n';
        }
    }
}