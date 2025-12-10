// Codeforces Round 974: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<bool> hs(n);
    while (h--) {
        int x;
        cin >> x;
        hs[x - 1] = 1;
    }
    // for (auto x : hs) cout << x << ' ';
    // cout << '\n';
    vector<vector<pair<int, int>>> adj(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // for (auto x : adj) {
    //     for (auto y : x) cout << y.f << ' ' << y.s << ',';
    //     cout << '\n';
    // }

    vector<int> M(n, -1);
    vector<bool> hvm(n, false);
    priority_queue<pair<pair<int, int>, bool>,
                   vector<pair<pair<int, int>, bool>>,
                   greater<pair<pair<int, int>, bool>>>
        Q;
    Q.push({{0, 0}, hs[0]});
    while (Q.size()) {
        auto curr = Q.top();
        Q.pop();
        // cout << curr.f.f << ' ' << curr.f.s << ' ' << curr.s << '\n';
        if (M[curr.f.s] != -1 && !curr.s) continue; // alr reached by foot
        if (hvm[curr.f.s]) continue;                // alr reached by horse
        M[curr.f.s] = M[curr.f.s] == -1 ? curr.f.f : min(M[curr.f.s], curr.f.f);
        if (curr.s) hvm[curr.f.s] = true; // reached by horse
        for (auto x : adj[curr.f.s]) {
            if (M[x.f] != -1 && !curr.s) continue; // also alr reached by foot
            if (hvm[x.f]) continue;                // also alr reached by horse
            // cout << (curr.f.f + (curr.s ? x.s / 2 : x.s)) << ' ';
            // cout << x.f << ' ' << (curr.s || hs[x.f]) << '\n';
            Q.push({{curr.f.f + (curr.s ? x.s / 2 : x.s), x.f},
                    curr.s || hs[x.f]});
        }
    }
    // cout << '\n';

    // for (auto x : M) cout << x << ' ';
    // cout << '\n' << '\n';

    vector<int> R(n, -1);
    vector<bool> hvr(n, false);
    Q.push({{0, n - 1}, hs[n - 1]});
    while (Q.size()) {
        auto curr = Q.top();
        Q.pop();
        // cout << curr.f.f << ' ' << curr.f.s << ' ' << curr.s << '\n';
        if (R[curr.f.s] != -1 && !curr.s) continue; // alr reached by foot
        if (hvr[curr.f.s]) continue;                // alr reached by horse
        R[curr.f.s] = R[curr.f.s] == -1 ? curr.f.f : min(R[curr.f.s], curr.f.f);
        if (curr.s) hvr[curr.f.s] = true; // reached by horse
        for (auto x : adj[curr.f.s]) {
            if (R[x.f] != -1 && !curr.s) continue; // also alr reached by foot
            if (hvr[x.f]) continue;                // also alr reached by horse
            Q.push({{curr.f.f + (curr.s ? x.s / 2 : x.s), x.f},
                    curr.s || hs[x.f]});
        }
    }

    // for (auto x : R) cout << x << ' ';
    // cout << '\n' << '\n';

    int ans = 1e18;
    for (int i = 0; i < n; i++) {
        if (M[i] == -1 || R[i] == -1) continue;
        ans = min(ans, max(M[i], R[i]));
    }
    cout << (ans == 1e18 ? -1 : ans) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}