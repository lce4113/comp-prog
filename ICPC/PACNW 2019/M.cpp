// 2019-2020 ICPC: Pacific Northwest Regionals
// Problem M

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

default_random_engine gen;
uniform_int_distribution<int> rng(0, 2);

struct DSU {
    vector<int> ps, sz;
    DSU(int n) : ps(n), sz(n, 1) {
        for (int i = 0; i < n; i++) ps[i] = i;
    }

    int f(int x) { return ps[x] == x ? x : (ps[x] = f(ps[x])); }
    bool sm(int x, int y) { return f(x) == f(y); }

    void u(int x, int y) {
        int xr = f(x), yr = f(y);
        if (xr == yr) return;
        if (sz[xr] < sz[yr]) swap(xr, yr);
        sz[xr] += sz[yr];
        ps[yr] = xr;
    }
    int cs() {
        set<int> rs;
        for (int i = 0; i < (int)ps.size(); i++) rs.insert(f(i));
        return rs.size();
    }
};

int n, m;
vector<vector<char>> a;

void join(DSU &d, int i, int j, int nx, int ny) {
    if (nx < 0 || nx >= n) {
        if (i >= 0 && i < n && j >= 0 && j < m) d.u(0, 1 + m * i + j);
        return;
    }
    if (ny < 0 || ny >= m) {
        if (i >= 0 && i < n && j >= 0 && j < m) d.u(0, 1 + m * i + j);
        return;
    }
    if (i < 0 || i >= n) {
        d.u(0, 1 + m * nx + ny);
        return;
    }
    if (j < 0 || j >= m) {
        d.u(0, 1 + m * nx + ny);
        return;
    }
    if (a[i][j] == '.' && a[nx][ny] == '.') d.u(1 + i * m + j, 1 + nx * m + ny);
}

void solve() {
    cin >> n >> m;
    a.assign(n, vector<char>(m));
    for (auto &x : a)
        for (auto &y : x) cin >> y;

    // for (auto x : a) {
    //     for (auto y : x) cout << y;
    //     cout << '\n';
    // }

    DSU d(1 + n * m);
    vector<int> dx, dy;
    dx = {0, 0, 1, -1};
    dy = {1, -1, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '/') {
                d.u(0, 1 + i * m + j);
                join(d, i - 1, j, i, j - 1);
                join(d, i, j + 1, i + 1, j);
                continue;
            }
            if (a[i][j] == '\\') {
                d.u(0, 1 + i * m + j);
                join(d, i - 1, j, i, j + 1);
                join(d, i, j - 1, i + 1, j);
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                join(d, i, j, nx, ny);
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << d.ps[1 + i * m + j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = d.cs() - 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] == '/' && a[i + 1][j + 1] == '/' &&
                a[i + 1][j] == '\\' && a[i][j + 1] == '\\')
                ans++;
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    // n = m = 10;
    // a.assign(n, vector<char>(m));
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         if (rng(gen) < 2) {
    //             a[i][j] = (i + j) % 2 ? '/' : '\\';
    //         } else {
    //             a[i][j] = '.';
    //         }
    //     }
    // }

    int t = 1;
    // cin >> t;
    while (t--) solve();
}