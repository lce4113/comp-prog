// Petrozavodsk 2020: Problem J

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

struct DSU {
    int n;
    vector<int> p, sz;
    DSU(int _n) : n(_n), p(_n), sz(_n, 1) { iota(p.begin(), p.end(), 0); }
    int r(int x) { return x == p[x] ? x : (p[x] = r(p[x])); }
    void u(int x, int y) {
        int rx = r(x), ry = r(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        sz[rx] += sz[ry];
        p[ry] = rx;
    }
};

void solve() {
    int n;
    cin >> n;
    // -1,y,z x,-1,z x,y,-1
    vector<array<int, 3>> a(n);
    map<array<int, 3>, int> mp;
    map<int, pair<vector<int>, bool>> mpx1, mpx2, mpy1, mpy2, mpz1, mpz2;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = {x, y, z};
        mp[{x, y, z}] = i;
        if (x == -1) {
            mpx1[y].f.push_back(i);
            mpx2[z].f.push_back(i);
        } else if (y == -1) {
            mpy1[x].f.push_back(i);
            mpy2[z].f.push_back(i);
        } else {
            mpz1[x].f.push_back(i);
            mpz2[y].f.push_back(i);
        }
    }

    DSU D(n);
    for (int i = 0; i < n; i++) {
        auto [x, y, z] = a[i];
        if (x == -1) {
            // -1,y,z

            // -1,y+1,z
            // -1,y-1,z
            // -1,y,z+1
            // -1,y,z-1

            // x,y,-1
            // x,y-1,-1
            // x,y+1,-1

            // x,-1,z
            // x-1,-1,z
            // x+1,-1,z
            vector<array<int, 3>> checkx = {
                {-1, y + 1, z}, {-1, y - 1, z}, {-1, y, z + 1}, {-1, y, z - 1}};
            vector<int> checky = {y, y - 1, y + 1};
            vector<int> checkz = {z, z - 1, z + 1};
            for (auto check : checkx) {
                if (mp.count(check)) {
                    D.u(mp[check], i);
                }
            }
            for (auto check : checky) {
                if (!mpz2.count(check)) continue;
                if (!mpz2[check].s) {
                    for (auto X : mpz2[check].f) {
                        D.u(mpz2[check].f[0], X);
                    }
                }
                mpz2[check].s = 1;
                D.u(mpz2[check].f[0], i);
            }
            for (auto check : checkz) {
                if (!mpy2.count(check)) continue;
                if (!mpy2[check].s) {
                    for (auto X : mpy2[check].f) {
                        D.u(mpy2[check].f[0], X);
                    }
                }
                mpy2[check].s = 1;
                D.u(mpy2[check].f[0], i);
            }
        } else if (y == -1) {
            // x,-1,z

            // x-1,-1,z
            // x+1,-1,z
            // x,-1,z-1
            // x,-1,z+1

            // x,y,-1
            // x-1,y,-1
            // x+1,y,-1

            // -1,y,z
            // -1,y,z+1
            // -1,y,z-1
            vector<array<int, 3>> checky = {
                {x - 1, -1, z}, {x + 1, -1, z}, {x, -1, z - 1}, {x, -1, z + 1}};
            vector<int> checkx = {x, x - 1, x + 1};
            vector<int> checkz = {z, z - 1, z + 1};
            for (auto check : checky) {
                if (mp.count(check)) {
                    D.u(mp[check], i);
                }
            }
            for (auto check : checkx) {
                if (!mpz1.count(check)) continue;
                if (!mpz1[check].s) {
                    for (auto X : mpz1[check].f) {
                        D.u(mpz1[check].f[0], X);
                    }
                }
                mpz1[check].s = 1;
                D.u(mpz1[check].f[0], i);
            }
            for (auto check : checkz) {
                if (!mpx2.count(check)) continue;
                if (!mpx2[check].s) {
                    for (auto X : mpx2[check].f) {
                        D.u(mpx2[check].f[0], X);
                    }
                }
                mpx2[check].s = 1;
                D.u(mpx2[check].f[0], i);
            }
        } else {
            // x,y,-1

            // x-1,y,-1
            // x+1,y,-1
            // x,y-1,-1
            // x,y+1,-1

            // x,-1,z
            // x-1,-1,z
            // x+1,-1,z

            // -1,y,z
            // -1,y+1,z
            // -1,y-1,z
            vector<array<int, 3>> checkz = {
                {x - 1, y, -1}, {x + 1, y, -1}, {x, y - 1, -1}, {x, y + 1, -1}};
            vector<int> checkx = {x, x - 1, x + 1};
            vector<int> checky = {z, z - 1, z + 1};
            for (auto check : checkz) {
                if (mp.count(check)) {
                    D.u(mp[check], i);
                }
            }
            for (auto check : checkx) {
                if (!mpy1.count(check)) continue;
                if (!mpy1[check].s) {
                    for (auto X : mpy1[check].f) {
                        D.u(mpy1[check].f[0], X);
                    }
                }
                mpy1[check].s = 1;
                D.u(mpy1[check].f[0], i);
            }
            for (auto check : checky) {
                if (!mpx1.count(check)) continue;
                if (!mpx1[check].s) {
                    for (auto X : mpx1[check].f) {
                        D.u(mpx1[check].f[0], X);
                    }
                }
                mpx1[check].s = 1;
                D.u(mpx1[check].f[0], i);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        array<int, 3> p1, p2, P1, P2;
        for (auto &x : p1) cin >> x;
        for (auto &x : p2) cin >> x;
        bool ok = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                P1 = p1, P2 = p2;
                P1[i] = -1, P2[j] = -1;
                if (!mp.count(P1) || !mp.count(P2)) continue;
                int i1 = mp[P1], i2 = mp[P2];
                if (D.r(i1) == D.r(i2)) ok = 1;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) solve();
}