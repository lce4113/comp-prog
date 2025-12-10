// Codeforces Round 1023: Problem D

// learning moment: write core logic first, then do precomputations and all
// supporting functions

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

set<array<int, 4>> dms;
vector<multiset<pair<int, int>>> chs;
vector<vector<int>> adj;
vector<int> p;

pair<int, int> hd(int i = 0, int P = 0) {
    p[i] = P;
    chs[i].insert({0, i}), chs[i].insert({0, i});
    for (auto x : adj[i]) {
        if (x == P) continue;
        chs[i].insert(hd(x, i));
    }
    auto mx1 = *chs[i].rbegin(), mx2 = *(++chs[i].rbegin());
    dms.insert({mx1.f + mx2.f, mx1.s, mx2.s, i});
    mx1.f++;
    return mx1;
}

void solve() {
    int n;
    cin >> n;
    dms.clear(), chs.clear(), adj.clear(), p.clear();
    p.assign(n, 0), adj.assign(n, {}), chs.assign(n, {});
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    hd();
    vector<array<int, 4>> ans;
    // 4 5 1 1
    // 4 5 4 4
    // 2 5 2 2
    vector<int> killed(n, 0);
    while (dms.size()) {
        // for (auto x : dms) {
        //     for (auto y : x) cout << y << ' ';
        //     cout << '\n';
        // }
        // for (auto x : chs) {
        //     for (auto y : x) cout << y.f << ' ' << y.s << ", ";
        //     cout << '\n';
        // }
        // cout << '\n';
        auto [ht, u, v, r] = *dms.rbegin();
        ans.push_back(*dms.rbegin());

        // update path to 1
        for (int c = p[r], prev = -1; prev != c; prev = c, c = p[c]) {
            if (killed[c]) continue;
            auto x = *chs[c].rbegin(), y = *(++chs[c].rbegin());
            dms.erase({x.f + y.f, x.s, y.s, c});
        }
        for (int c = r; p[c] != c; c = p[c]) {
            if (killed[p[c]] || killed[c]) continue;
            auto x = *chs[c].rbegin();
            x.f++;
            chs[p[c]].erase(x);
        }
        for (int c = p[r]; p[c] != c; c = p[c]) {
            if (killed[p[c]] || killed[c]) continue;
            auto x = *chs[c].rbegin();
            x.f++;
            chs[p[c]].insert(x);
        }
        for (int c = p[r], prev = -1; prev != c; prev = c, c = p[c]) {
            if (killed[c]) continue;
            auto x = *chs[c].rbegin(), y = *(++chs[c].rbegin());
            dms.insert({x.f + y.f, x.s, y.s, c});
        }

        // kill diam
        dms.erase(*dms.rbegin());
        killed[r] = 1;
        for (int c = u; c != r; c = p[c]) {
            auto x = *chs[c].rbegin(), y = *(++chs[c].rbegin());
            dms.erase({x.f + y.f, x.s, y.s, c});
            killed[c] = 1;
        }
        for (int c = v; c != r; c = p[c]) {
            auto x = *chs[c].rbegin(), y = *(++chs[c].rbegin());
            dms.erase({x.f + y.f, x.s, y.s, c});
            killed[c] = 1;
        }
    }
    for (auto x : ans) {
        if (x[1] < x[2]) swap(x[1], x[2]);
        cout << x[0] + 1 << ' ' << x[1] + 1 << ' ' << x[2] + 1 << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}