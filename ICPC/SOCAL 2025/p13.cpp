// ICPC Socal Regionals 2025: Problem 13

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int M = 1e9 + 7;

struct DSU {
    int n, comps;
    vector<int> p, sz;
    DSU(int _n) : n(_n), p(n), sz(n, 1) {
        comps = n;
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int r(int x) { return x == p[x] ? x : (p[x] = r(p[x])); }
    void u(int x, int y) {
        int rx = r(x), ry = r(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        sz[rx] += sz[ry];
        p[ry] = rx;
        comps--;
    }
};

void rset(vector<int> &req, int hi, int val) {
    if (req[hi] == 1 - val) {
        cout << "0\n";
        exit(0);
    }
    req[hi] = val;
}

int binexp(int a, int b = M - 2) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= M) {
        if (b % 2) res *= a, res %= M;
    }
    return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, N;
    cin >> n >> m >> N;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    vector<pair<string, string>> ws(N);
    for (auto &x : ws) cin >> x.f >> x.s;

    // x,y,v/h,len
    vector<array<int, 4>> ps;
    for (int i = 0; i < n; i++) {
        int start = -1;
        if (a[i][0] == '.') start = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#' && j + 1 < m && a[i][j + 1] == '.') {
                start = j + 1;
            }
            if (a[i][j] == '.' && (j + 1 == m || a[i][j + 1] == '#')) {
                if (j != start) {
                    ps.push_back({i, start, 0, j - start + 1});
                }
                start = -1;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        int start = -1;
        if (a[0][j] == '.') start = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == '#' && i + 1 < n && a[i + 1][j] == '.') {
                start = i + 1;
            }
            if (a[i][j] == '.' && (i + 1 == n || a[i + 1][j] == '#')) {
                if (i != start) {
                    ps.push_back({start, j, 1, i - start + 1});
                }
                start = -1;
            }
        }
    }
    sort(ps.begin(), ps.end());
    vector<vector<int>> HS(n, vector<int>(m, -1));
    vector<vector<int>> VS(n, vector<int>(m, -1));
    for (int i = 0; i < N; i++) {
        if (ps[i][2]) {
            for (int x = ps[i][0]; x < ps[i][0] + ps[i][3]; x++) {
                VS[x][ps[i][1]] = i;
            }
        } else {
            for (int y = ps[i][1]; y < ps[i][1] + ps[i][3]; y++) {
                HS[ps[i][0]][y] = i;
            }
        }
    }
    DSU D(2 * N + 2);
    vector<int> req(N, -1);
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (HS[x][y] == -1 || VS[x][y] == -1) continue;
            int i = HS[x][y], j = VS[x][y];
            auto [hx, hy, _1, hl] = ps[i];
            auto [vx, vy, _2, vl] = ps[j];
            // cout << i << ' ' << j << ' ' << vl << ' ' << hl << '\n';
            // cout << hx << ' ' << vx << ' ' << ws[j].f << '\n';
            char va = ws[j].f[x - vx], vb = ws[j].s[hx - vx];
            char ha = ws[i].f[y - hy], hb = ws[i].s[vy - hy];
            // cout << va << ' ' << vb << ' ' << ha << ' ' << hb << '\n';
            int cnt = set<char>({va, vb, ha, hb}).size();
            // a/b, c/d
            if (cnt == 4) {
                cout << "0\n";
                return 0;
            }
            // a/b, a/c
            if (cnt == 3) {
                if (va != vb && ha != hb) {
                    if (va == ha) rset(req, j, 0), rset(req, i, 0);
                    if (va == hb) rset(req, j, 0), rset(req, i, 1);
                    if (vb == ha) rset(req, j, 1), rset(req, i, 0);
                    if (vb == hb) rset(req, j, 1), rset(req, i, 1);
                } else {
                    cout << "0\n";
                    return 0;
                }
            }
            if (cnt == 2) {
                // a/b, a/a
                if (va == vb) {
                    if (ha == va) rset(req, i, 0);
                    if (hb == va) rset(req, i, 1);
                } else if (ha == hb) {
                    if (va == ha) rset(req, j, 0);
                    if (vb == ha) rset(req, j, 1);
                } else { // a/b, a/b
                    if (ha == va) D.u(i, j), D.u(i + N, j + N);
                    if (ha == vb) D.u(i, j + N), D.u(i + N, j);
                }
            }
            // a/a, a/a
            if (cnt == 1) {
                continue;
            }
        }
    }
    // for (auto x : ps) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }
    for (int i = 0; i < N; i++) {
        if (req[i] == 0) {
            D.u(i, 2 * N);
            D.u(i + N, 2 * N + 1);
        }
        if (req[i] == 1) {
            D.u(i, 2 * N + 1);
            D.u(i + N, 2 * N);
        }
    }
    for (int i = 0; i < N; i++) {
        if (D.r(i) == D.r(i + N)) {
            cout << "0\n";
            return 0;
        }
    }
    cout << binexp(2, (D.comps - 2) / 2) << '\n';
}