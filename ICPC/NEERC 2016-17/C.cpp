// NEERC 2016-17: Problem C

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

map<int, int> ps;
vector<int> pr;

struct Tree {
    int n = 1 << 13;
    vector<ll> a;
    Tree() : a(2 * n) {}
    void u(int pos, int val) {
        for (a[pos += n] += val; pos /= 2;) {
            a[pos] = a[pos * 2] + a[pos * 2 + 1];
        }
    }
    ll q(int l, int r) {
        ll ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans += a[l++];
            if (r % 2) ans += a[--r];
        }
        return ans;
    }
    int walk(int k, int i = 1) {
        if (i >= n) return i - n;
        if (k > a[2 * i]) return walk(k - a[2 * i], 2 * i + 1);
        return walk(k, 2 * i);
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int w;
    cin >> w;
    vector<pair<int, int>> ws[n];
    while (w--) {
        int c, k, p;
        cin >> c >> k >> p;
        c--;
        ws[c].push_back({k, p});
        ps[p];
    }
    int C = 0;
    for (auto &[v, c] : ps) c = C++, pr.push_back(v);
    Tree cnt[n];
    Tree cst[n];
    // for (auto x : ps) cout << x.f << ' ' << x.s << '\n';
    int q;
    cin >> q;
    vector<array<int, 3>> qs(q);
    vector<int> ans(q, -1);
    for (auto &x : qs) {
        cin >> x[0] >> x[1] >> x[2];
    }
    queue<pair<int, int>> Q[n];
    bool vis[n][n];
    memset(vis, 0, sizeof(vis));
    for (int j = 0; j < n; j++) {
        vis[j][j] = 1;
        Q[j].push({j, 0});
    }
    for (int d = 0; d < n; d++) {
        // simultaneous bfs, update cnt and cst
        for (int j = 0; j < n; j++) {
            while (Q[j].size() && Q[j].front().s <= d) {
                if (Q[j].empty()) continue;
                auto [v, cd] = Q[j].front();
                Q[j].pop();
                for (auto w : ws[v]) {
                    cnt[j].u(ps[w.s], w.f);
                    cst[j].u(ps[w.s], (ll)w.s * w.f);
                }
                for (auto to : g[v]) {
                    if (vis[j][to]) continue;
                    vis[j][to] = 1;
                    Q[j].push({to, cd + 1});
                }
            }
        }
        // check if queries are satisfied
        for (int j = 0; j < q; j++) {
            if (ans[j] != -1) continue;
            // qs[j] -> {city, shovels, max burles}
            auto [c, shovels, burles] = qs[j];
            c--;
            if (cnt[c].q(0, C) < shovels) continue;
            int p = cnt[c].walk(shovels);
            int rem = shovels - cnt[c].q(0, p);
            if ((ll)rem * pr[p] + cst[c].q(0, p) <= burles) {
                ans[j] = d;
            }
        }
    }
    for (auto x : ans) cout << x << '\n';
}