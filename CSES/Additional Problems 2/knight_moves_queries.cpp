// CSES Additional Problems II: Knight Moves Queries

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
vector<vector<int>> precomp(MAXN, vector<int>(MAXN, -1));

void solve() {
    int x, y;
    cin >> x >> y;
    if (x < y) swap(x, y);
    x--, y--;
    if (x < MAXN && y < MAXN) {
        cout << precomp[x][y] << '\n';
        return;
    }
    int ans = 0;
    int hops = min((x - MAXN) / 2 + 1, x - y);
    x -= 2 * hops, y -= hops, ans += hops;
    if (y < 0) y = (y % 2 + 2) % 2;
    if (x >= MAXN) {
        hops = (x - MAXN) / 3 + 1;
        x -= 3 * hops, y -= 3 * hops, ans += 2 * hops;
    }
    cout << ans + precomp[x][y] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
    queue<pair<int, int>> Q;
    Q.emplace(0, 0);
    precomp[0][0] = 0;
    while (Q.size()) {
        auto [x, y] = Q.front();
        Q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= MAXN) continue;
            if (ny < 0 || ny >= MAXN) continue;
            if (precomp[nx][ny] != -1) continue;
            precomp[nx][ny] = precomp[x][y] + 1;
            Q.emplace(nx, ny);
        }
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}