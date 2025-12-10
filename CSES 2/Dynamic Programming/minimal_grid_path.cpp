// CSES Dynamic Programming: Minimal Grid Path

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    vector<pair<int, int>> ps, nps;
    ps.push_back({0, 0});
    cout << a[0][0];
    for (int i = 0; i <= 2 * n - 3; i++) {
        nps.clear();
        char mn = 'Z';
        for (auto p : ps) {
            auto [x, y] = p;
            if (x + 1 < n && !vis[x + 1][y]) {
                nps.push_back({x + 1, y}), mn = min(a[x + 1][y], mn);
                vis[x + 1][y] = 1;
            }
            if (y + 1 < n && !vis[x][y + 1]) {
                nps.push_back({x, y + 1}), mn = min(a[x][y + 1], mn);
                vis[x][y + 1] = 1;
            }
        }
        cout << mn;
        ps.clear();
        for (auto p : nps) {
            auto [x, y] = p;
            if (a[x][y] == mn) ps.push_back(p);
        }
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}