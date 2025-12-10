// Codeforces Round 998: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct DSU {
    vector<int> ps, sz;

    DSU(int n) : ps(n), sz(n, 1) {
        for (int i = 0; i < n; i++) ps[i] = i;
    }

    int f(int x) { return ps[x] == x ? x : (ps[x] = f(ps[x])); }
    bool same(int x, int y) { return f(x) == f(y); }

    void u(int x, int y) {
        int xr = f(x), yr = f(y);
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

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<set<int>> adj1(n), adj2(n);
    while (m1--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj1[a].insert(b);
        adj1[b].insert(a);
    }
    DSU d(n);
    while (m2--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj2[a].insert(b);
        adj2[b].insert(a);
        d.u(a, b);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> es;
        for (auto x : adj1[i]) {
            if (!d.same(x, i)) {
                ans++;
                // cout << x << ' ' << i << '\n';
                // cout << ans << '\n';
                es.push_back(x);
            }
        }
        for (auto x : es) adj1[i].erase(x);
    }
    // cout << ans << '\n';
    ans /= 2;

    DSU d2(n);
    for (int i = 0; i < n; i++) {
        for (auto x : adj1[i]) d2.u(i, x);
    }

    // cout << d.cs() << ' ' << d2.cs() << '\n';
    ans += d2.cs() - d.cs();

    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}