// CSES Additional Problems II: School Excursion

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

struct DSU {
    int n;
    vector<int> p, sz;
    DSU(int _n) : n(_n), p(_n), sz(_n, 1) {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int root(int x) { return x == p[x] ? x : (p[x] = root(p[x])); }
    void u(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx == ry) return;
        if (sz[rx] < sz[ry]) swap(rx, ry);
        p[ry] = rx;
        sz[rx] += sz[ry];
        sz[ry] = 0;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    DSU D(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        D.u(x, y);
    }
    map<int, int> mp;
    for (auto x : D.sz) {
        if (x != 0) mp[x]++;
    }
    bitset<MAXN + 1> ans;
    ans[0] = 1;
    for (auto [v, cnt] : mp) {
        for (int e = 1; e <= cnt; e *= 2) {
            ans |= ans << (v * e);
            cnt -= e;
        }
        ans |= ans << (v * cnt);
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
    cout << '\n';
}