// Codeforces Round 1067: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct DSU {
    int n, ans;
    vector<int> p, sz, hole;
    DSU(int _n) : n(_n), ans(n), p(n, 1), sz(n, 1), hole(n, 1) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    void set(int x, bool b = 0) {
        ans -= hole[r(x)];
        hole[r(x)] = b;
        ans += hole[r(x)];
    }
    int r(int x) { return x == p[x] ? x : (p[x] = r(p[x])); }
    void u(int x, int y) {
        int rx = r(x), ry = r(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        if (hole[ry] == 0) set(rx);
        set(ry);
        sz[rx] += sz[ry];
        p[ry] = rx;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> ind(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ind[i][j] = i * m + j;
        }
    }
    for (auto &x : a) {
        for (auto &y : x) cin >> y;
    }
    int q;
    cin >> q;
    int cur = n * m;
    DSU D(n * m + q);
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            for (int i = 0; i < 4; i++) {
                int x = r + dx[i], y = c + dy[i];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                if (a[x][y] == a[r][c]) {
                    D.u(ind[x][y], ind[r][c]);
                } else if (a[r][c] < a[x][y]) {
                    D.set(ind[x][y]);
                } else {
                    D.set(ind[r][c]);
                }
            }
        }
    }
    cout << D.ans - (D.n - cur) << '\n';
    while (q--) {
        int r, c, v;
        cin >> r >> c >> v;
        r--, c--;
        if (D.sz[D.r(ind[r][c])] > 1) {
            ind[r][c] = cur++;
        }
        D.set(ind[r][c], 1);
        a[r][c] -= v;
        for (int i = 0; i < 4; i++) {
            int x = r + dx[i], y = c + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (a[x][y] == a[r][c]) {
                D.u(ind[x][y], ind[r][c]);
            } else if (a[r][c] < a[x][y]) {
                D.set(ind[x][y]);
            } else {
                D.set(ind[r][c]);
            }
        }
        cout << D.ans - (D.n - cur) << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}