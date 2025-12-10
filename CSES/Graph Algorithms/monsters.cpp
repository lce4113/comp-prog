// CSES Graph Algorithms: Monsters

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<bool>> M(n, vector<bool>(m, 0));
    vector<string> p(n, string(m, '.'));
    pair<int, int> A;
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'M') Q.push({i, j}), M[i][j] = 1, p[i][j] = 'U';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') Q.push({i, j}), p[i][j] = 'U', A = {i, j};
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    string ds = "LRDU";
    while (Q.size()) {
        auto [x, y] = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + x, ny = dy[i] + y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                if (M[x][y]) continue;
                cout << "YES\n";
                string ans;
                pair<int, int> c = {x, y};
                // for (auto x : p) cout << x << '\n';
                while (c != A) {
                    // cout << c.f << ' ' << c.s << '\n';
                    // if (c.f < 0 || c.f >= n) return;
                    // if (c.s < 0 || c.s >= m) return;
                    ans += p[c.f][c.s];
                    if (p[c.f][c.s] == 'L') {
                        c.s++;
                    } else if (p[c.f][c.s] == 'R') {
                        c.s--;
                    } else if (p[c.f][c.s] == 'U') {
                        c.f++;
                    } else {
                        c.f--;
                    }
                }
                reverse(ans.begin(), ans.end());
                cout << ans.size() << '\n';
                cout << ans << '\n';
                return;
            }
            if (a[nx][ny] == '#') continue;
            if (p[nx][ny] != '.') continue;
            Q.push({nx, ny});
            M[nx][ny] = M[x][y];
            p[nx][ny] = ds[i];
        }
    }
    cout << "NO\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}