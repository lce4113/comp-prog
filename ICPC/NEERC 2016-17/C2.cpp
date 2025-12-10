// NEERC 2016-2017: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int w;
    cin >> w;
    vector<pair<int, int>> stores[n];
    while (w--) {
        int c, cnt, pr;
        cin >> c >> cnt >> pr;
        c--;
        stores[c].push_back({pr, cnt});
    }

    int q;
    cin >> q;
    while (q--) {
        int c, sh, bu;
        cin >> c >> sh >> bu;
        c--;

        // price, count, dist
        vector<pair<pair<int, int>, int>> pr;
        queue<pair<int, int>> Q;
        bool vis[n];
        memset(vis, 0, sizeof(vis));
        Q.push({c, 0});
        vis[c] = 1;
        while (Q.size()) {
            auto [v, d] = Q.front();
            Q.pop();
            for (auto store : stores[v]) pr.push_back({store, d});
            for (auto to : g[v]) {
                if (vis[to]) continue;
                vis[to] = 1;
                Q.push({to, d + 1});
            }
        }
        sort(pr.begin(), pr.end());

        int l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            vector<pair<int, int>> cpr;
            for (auto [store, d] : pr) {
                if (d <= m) cpr.push_back(store);
            }
            bool ok = 0;
            for (int i = 0, cnt = 0, tot = 0; i < cpr.size(); i++) {
                if (cnt + cpr[i].s >= sh) {
                    int tot2 = tot + (sh - cnt) * cpr[i].f;
                    if (tot2 <= bu) {
                        r = m;
                    } else {
                        l = m;
                    }
                    ok = 1;
                    break;
                }
                cnt += cpr[i].s;
                tot += cpr[i].s * cpr[i].f;
            }
            if (!ok) {
                l = m;
            }
        }
        cout << (r == n ? -1 : r) << '\n';
    }
}