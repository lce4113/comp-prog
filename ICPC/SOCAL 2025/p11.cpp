// ICPC Socal Regionals: Problem 11

#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<vector<pair<int, int>>> g;
vector<int> cy;
vector<bool> vis;
vector<int> path;
vector<int> cy_dist;
vector<bool> on_cy;
vector<int> depth;
vector<int> upd;
vector<vector<int>> downd;
const int INF = 1e18;

struct MxTree {
    int n;
    vector<int> a;
    MxTree(int _n) : n(_n), a(2 * n, -INF) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = max(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        if (l == r) return -INF;
        int res = -INF;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) res = max(res, a[l++]);
            if (r % 2) res = max(res, a[--r]);
        }
        return res;
    }
};
struct MnTree {
    int n;
    vector<int> a;
    MnTree(int _n) : n(_n), a(2 * n, INF) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = min(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        if (l == r) return INF;
        int res = INF;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) res = min(res, a[l++]);
            if (r % 2) res = min(res, a[--r]);
        }
        return res;
    }
};

void pre(int v, int p) {
    vis[v] = 1;
    path.push_back(v);
    for (auto [to, w] : g[v]) {
        if (to == p) continue;
        if (vis[to]) {
            int p = find(path.begin(), path.end(), to) - path.begin();
            for (int i = p; i < path.size(); i++) cy.push_back(path[i]);
            return;
        }
        pre(to, v);
    }
    path.pop_back();
}

void dst(int v) {
    vis[v] = 1;
    downd[v].push_back(0);
    for (auto [to, w] : g[v]) {
        if (on_cy[to] || vis[to]) continue;
        dst(to);
        downd[v].push_back(depth[to] + w);
    }
    sort(downd[v].rbegin(), downd[v].rend());
    depth[v] = downd[v][0];
}

void dfsu(int v) {
    vis[v] = 1;
    for (auto [to, w] : g[v]) {
        if (on_cy[to] || vis[to]) continue;
        upd[to] = upd[v] + w;
        if (depth[to] + w == downd[v][0]) {
            upd[to] = max(upd[to], downd[v][1] + w);
        } else {
            upd[to] = max(upd[to], downd[v][0] + w);
        }
        dfsu(to);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    g.assign(n, {});
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vis.assign(n, 0);
    pre(0, 0);
    on_cy.assign(n, 0);
    for (auto x : cy) on_cy[x] = 1;

    cy_dist = cy;
    cy_dist[0] = 0;
    int tot = 0;
    for (int i = 1; i < cy.size(); i++) {
        for (auto [to, w] : g[cy[i - 1]]) {
            if (to == cy[i]) cy_dist[i] = cy_dist[i - 1] + w, tot += w;
        }
    }
    for (auto [to, w] : g[cy.back()]) {
        if (to == cy[0]) tot += w;
    }
    for (int i = 0; i < cy.size(); i++) cy_dist.push_back(cy_dist[i] + tot);

    vis.assign(n, 0);
    depth.assign(n, 0);
    downd.assign(n, {});
    MnTree mnt(2 * cy.size());
    MxTree mxt(2 * cy.size());
    for (int i = 0; i < cy.size(); i++) {
        dst(cy[i]);
        mxt.u(i, cy_dist[i] + depth[cy[i]]);
        mxt.u(i + cy.size(), cy_dist[i] + depth[cy[i]] + tot);
        mnt.u(i, cy_dist[i] - depth[cy[i]]);
        mnt.u(i + cy.size(), cy_dist[i] - depth[cy[i]] + tot);
    }

    queue<pair<int, int>> Q;
    set<int> cur;
    upd.assign(n, 0);
    for (int i = 0; i < cy.size(); i++) {
        int B =
            upper_bound(cy_dist.begin(), cy_dist.end(), cy_dist[i] + tot / 2) -
            cy_dist.begin();
        int L = -cy_dist[i] + mxt.q(i + 1, B);
        int R = cy_dist[i + cy.size()] - mnt.q(B, i + cy.size());
        upd[cy[i]] = max(L, R);
    }

    vis.assign(n, 0);
    for (int i = 0; i < cy.size(); i++) {
        dfsu(cy[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << max(upd[i], downd[i][0]) << ' ';
    }
    cout << '\n';
}