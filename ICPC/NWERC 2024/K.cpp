// NWERC 2024: Problem K

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define db long double
const int INF = 1e18;
const int EPS = 1e-6;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> dst(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    dst[0] = 0;
    Q.push({0, 0});
    while (Q.size()) {
        auto [d, v] = Q.top();
        Q.pop();
        if (dst[v] != d) continue;
        for (auto [to, w] : g[v]) {
            if (d + w < dst[to]) {
                dst[to] = d + w;
                Q.push({dst[to], to});
            }
        }
    }
    vector<int> dst2(n, INF);
    dst2[n - 1] = 0;
    Q.push({0, n - 1});
    while (Q.size()) {
        auto [d, v] = Q.top();
        Q.pop();
        if (dst2[v] != d) continue;
        for (auto [to, w] : g[v]) {
            if (d + w < dst2[to]) {
                dst2[to] = d + w;
                Q.push({dst2[to], to});
            }
        }
    }
    vector<pair<int, db>> shops;
    bool ok = 0;
    while (k--) {
        int i;
        db pr;
        cin >> i >> pr;
        i--;
        shops.push_back({dst[i] + dst2[i], pr});
        if (fabs(pr - 1) <= EPS) ok = 1;
    }
    if (!ok) {
        cout << "impossible\n";
        return 0;
    }
    sort(shops.begin(), shops.end());
    db ans = 0, cpr = 1;
    for (auto [d, pr] : shops) {
        ans += cpr * pr * d;
        cpr *= (db)1 - pr;
    }
    cout << ans << '\n';
}