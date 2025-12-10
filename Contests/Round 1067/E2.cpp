// Codeforces Round 1067: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct DSU {
    vector<vector<pair<int, int>>> par;
    vector<vector<int>> sz, vals;
    vector<vector<bool>> hole;
    vector<array<int, 9>> hist;
    int ans;
    DSU() {
        ans = n * m;
        par.assign(n, vector<pair<int, int>>(m));
        sz.assign(n, vector<int>(m, 1));
        hole.assign(n, vector<bool>(m, 1));
        vals.assign(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                par[i][j] = {i, j};
            }
        }
    }
    pair<int, int> r(pair<int, int> p) {
        return p == par[p.f][p.s] ? p : r(par[p.f][p.s]);
    }
    void join(pair<int, int> p1, pair<int, int> p2) {
        auto r1 = r(p1), r2 = r(p2);
        if (r1 == r2) return;
        if (sz[r1.f][r1.s] < sz[r2.f][r2.s]) swap(r1, r2);
        hist.push_back({1, r1.f, r1.s, sz[r1.f][r1.s], hole[r1.f][r1.s], r2.f,
                        r2.s, hole[r2.f][r2.s], 0});
        if (hole[r2.f][r2.s])
            seth(r2.f, r2.s, 0);
        else
            seth(r1.f, r1.s, 0);
        par[r2.f][r2.s] = r1;
        sz[r1.f][r1.s] += sz[r2.f][r2.s];
    }
    void u(int x, int y, int v) {
        int M = geth(x, y);
        int L = y - 1 >= 0 ? geth(x, y - 1) : 0;
        int R = y + 1 < m ? geth(x, y + 1) : 0;
        int U = x - 1 >= 0 ? geth(x - 1, y) : 0;
        int D = x + 1 < n ? geth(x + 1, y) : 0;
        hist.push_back({0, x, y, vals[x][y], M, L, R, U, D});
        vals[x][y] = v;
        for (int k = 0; k < 4; k++) {
            int nx = dx[k] + x, ny = dy[k] + y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vals[nx][ny] == -1) continue;
            if (vals[nx][ny] == vals[x][y]) {
                join({x, y}, {nx, ny});
            } else if (vals[nx][ny] < vals[x][y]) {
                seth(x, y, 0);
            } else {
                seth(nx, ny, 0);
            }
        }
    }
    bool geth(int x, int y) {
        auto rp = r({x, y});
        return hole[rp.f][rp.s];
    }
    void seth(int x, int y, bool b) {
        if (x < 0 || x >= n || y < 0 || y >= m) return;
        auto rp = r({x, y});
        ans -= hole[rp.f][rp.s];
        hole[rp.f][rp.s] = b;
        ans += hole[rp.f][rp.s];
    }
    int snap() { return hist.size(); }
    void roll(int snapshot) {
        while (hist.size() > snapshot) {
            if (hist.back()[0]) {
                auto [_, px, py, szp, hp, cx, cy, hc, _1] = hist.back();
                par[cx][cy] = {cx, cy};
                sz[px][py] = szp;
                seth(px, py, hp);
                seth(cx, cy, hc);
            } else {
                auto [_, x, y, v, M, L, R, U, D] = hist.back();
                vals[x][y] = v;
                seth(x, y, M);
                seth(x - 1, y, U);
                seth(x + 1, y, D);
                seth(x, y - 1, L);
                seth(x, y + 1, R);
            }
            hist.pop_back();
        }
    }
};
struct QTree {
    DSU D;
    int q;
    vector<vector<array<int, 3>>> a;
    vector<int> ans;
    QTree(int _q) {
        q = 1 << (__lg(_q) + 1);
        ans.assign(q, 0);
        a.assign(2 * q, {});
    }
    void u(int x, int y, int l, int r, int v) {
        for (l += q, r += q; l < r; l /= 2, r /= 2) {
            if (l & 1) a[l++].push_back({x, y, v});
            if (r & 1) a[--r].push_back({x, y, v});
        }
    }
    void dfs(int i = 1) {
        int snap = D.snap();

        for (auto [x, y, v] : a[i]) {
            D.u(x, y, v);
        }

        if (i >= q) {
            ans[i - q] = D.ans;
        } else {
            dfs(i * 2);
            dfs(i * 2 + 1);
        }

        D.roll(snap);
    }
};

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a) {
        for (auto &y : x) cin >> y;
    }
    vector<vector<pair<int, int>>> qs(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) qs[i][j] = {0, a[i][j]};
    }
    int q;
    cin >> q;
    QTree Q(q + 1);
    for (int i = 1; i <= q; i++) {
        int r, c, v;
        cin >> r >> c >> v;
        r--, c--;
        a[r][c] -= v;
        Q.u(r, c, qs[r][c].f, i, qs[r][c].s);
        qs[r][c] = {i, a[r][c]};
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Q.u(i, j, qs[i][j].f, q + 1, qs[i][j].s);
        }
    }
    Q.dfs();
    for (int i = 0; i <= q; i++) {
        cout << Q.ans[i] << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}