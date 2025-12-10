#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> rem(n, 1);
    int remc = n;
    vector<array<int, 3>> ans;
    while (remc) {
        vector<bool> vis(n, 0);
        vector<int> p(n, -2);
        for (int i = 0; i < n; i++) {
            if (rem[i] == 0 || vis[i] == 1) continue;
            int d1, d2, mxd = -1;
            queue<pair<int, int>> Q;
            Q.push({i, 0});
            vis[i] = 1;
            while (Q.size()) {
                auto [c, dst] = Q.front();
                Q.pop();
                if (dst > mxd) mxd = dst, d1 = c;
                if (dst == mxd) d1 = max(d1, c);
                for (auto x : adj[c]) {
                    if (vis[x]) continue;
                    if (rem[x] == 0) continue;
                    vis[x] = 1;
                    Q.push({x, dst + 1});
                }
            }
            Q.push({d1, 0});
            p[d1] = -1, mxd = -1;
            while (Q.size()) {
                auto [c, dst] = Q.front();
                Q.pop();
                if (dst > mxd) mxd = dst, d2 = c;
                if (dst == mxd) d2 = max(d2, c);
                for (auto x : adj[c]) {
                    if (p[x] != -2) continue;
                    if (rem[x] == 0) continue;
                    p[x] = c;
                    Q.push({x, dst + 1});
                }
            }
            for (int c = d2; c != -1; c = p[c]) {
                rem[c] = 0;
                remc--;
            }
            if (d1 < d2) swap(d1, d2);
            ans.push_back({mxd, d1, d2});
        }
    }

    sort(ans.rbegin(), ans.rend());
    for (auto x : ans) {
        for (auto y : x) cout << y + 1 << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}