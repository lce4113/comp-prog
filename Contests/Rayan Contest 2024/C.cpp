// Rayan Programming Contest 2024: Problem C

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> b(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            int x = i, y = j;
            vector<pair<int, int>> path;
            while (x < n && y < m && x >= 0 && y >= 0 && !vis[x][y]) {
                vis[x][y] = true;
                path.push_back({x, y});
                if (a[x][y] == 'R')
                    y++;
                else if (a[x][y] == 'L')
                    y--;
                else if (a[x][y] == 'U')
                    x--;
                else if (a[x][y] == 'D')
                    x++;
                else if (a[x][y] == '?') {
                    if (y - 1 >= 0 &&
                        (a[x][y - 1] == 'R' || a[x][y - 1] == '?'))
                        a[x][y] = 'L', y--;
                    else if (y + 1 < m &&
                             (a[x][y + 1] == 'L' || a[x][y + 1] == '?'))
                        a[x][y] = 'R', y++;
                    else if (x + 1 < n &&
                             (a[x + 1][y] == 'U' || a[x + 1][y] == '?'))
                        a[x][y] = 'D', x++;
                    else if (x - 1 >= 0 &&
                             (a[x - 1][y] == 'D' || a[x - 1][y] == '?'))
                        a[x][y] = 'U', x--;
                }
            }
            if (!(x < n && y < m && x >= 0 && y >= 0)) {
                for (auto p : path) b[p.f][p.s] = 0;
                continue;
            }
            if (a[x][y] == '?') continue;
            if (vis[x][y] && !b[x][y]) {
                for (auto p : path) b[p.f][p.s] = 0;
            }
            if (vis[x][y] && b[x][y]) {
                for (auto p : path) b[p.f][p.s] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cout << a[i][j] << b[i][j] << ' ';
            ans += (b[i][j] == 1);
        }
        // cout << '\n';
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '?') continue;
            for (int k = 0; k < 4; k++) {
                int xn = i + dx[k], yn = j + dy[k];
                if (!(xn < n && yn < m && xn >= 0 && yn >= 0)) continue;
                // cout << xn << ' ' << yn << ' ' << b[xn][yn] << '\n';
                if (b[xn][yn]) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}