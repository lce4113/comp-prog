// USACO 2025 February Gold
// Problem 1. "Bessie's Function"

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n;
vector<int> ps, cst;
vector<vector<int>> adj;

pair<int, int> rec(int c, int sk, int cost) {
    // cout << "ps: " << c << ' ' << sk << '\n';
    if (adj[c].size() == 0) {
        // cout << c << ' ' << cst[c] << ' ' << 0 << '\n';
        return {cst[c], 0};
    }
    int res = 0, sm = 0;
    for (auto x : adj[c]) {
        if (x == sk) continue;
        auto p = rec(x, -1, cst[x]);
        res += min(p.f, p.s);
        sm += p.f;
    }
    // cout << c << ' ' << cst[c] + res << ' ' << sm << '\n';
    return {cost + res, sm};
}

void solve() {
    cin >> n;
    ps.assign(n, 0), cst.assign(n, 0);
    for (auto &x : ps) {
        cin >> x;
        x--;
    }
    adj.assign(n, {});
    for (int i = 0; i < n; i++) adj[ps[i]].push_back(i);
    for (auto &x : cst) cin >> x;

    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (auto x : adj[i]) cout << x << ' ';
    //     cout << '\n';
    // }

    vector<vector<int>> cycles;
    set<int> unvis;
    for (int i = 0; i < n; i++) unvis.insert(i);
    while (unvis.size()) {
        int st = *unvis.begin();
        set<int> path;
        path.insert(st);
        int c = ps[st];
        bool brk = false;
        while (!path.count(c)) {
            path.insert(c);
            c = ps[c];
            if (!unvis.count(c)) {
                brk = true;
                break;
            }
        }
        for (auto x : path) unvis.erase(x);
        if (brk) continue;
        // for (auto x : cycs) cout << x << ' ';
        // cout << '\n';
        // cout << "c: " << c << '\n';
        st = c;
        c = ps[c];
        vector<int> cyc(1, st);
        while (c != st) {
            cyc.push_back(c);
            c = ps[c];
        }
        cycles.push_back(cyc);
    }

    int ans = 0;
    for (auto cyc : cycles) {
        int N = cyc.size();
        vector<int> sub(N);
        for (int i = 0; i < N; i++) {
            auto res =
                rec(cyc[i], cyc[(i - 1 + N) % N], N == 1 ? 0 : cst[cyc[i]]);
            // cout << cyc[i] << ' ' << cst[cyc[i]] << '\n';
            // cout << cyc[i] << ' ' << res.f << ' ' << res.s << '\n';
            sub[i] = res.s - res.f;
            ans += res.f;
        }

        pair<int, int> dp = {sub[0], sub[0]}, ndp;
        for (int i = 2; i < N - 1; i++) {
            ndp = {sub[i] + dp.s, min(dp.f, dp.s)};
            dp = ndp;
        }
        int S = min(dp.f, dp.s);

        dp = {0, 0};
        for (int i = 1; i < N; i++) {
            ndp = {sub[i] + dp.s, min(dp.f, dp.s)};
            dp = ndp;
        }
        S = min(S, min(dp.f, dp.s));

        ans += S;
    }

    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}