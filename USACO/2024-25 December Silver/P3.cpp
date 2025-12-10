// USACO 2024-25 December Contest, Silver
// Problem 3. "2D Conveyer Belt"

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

const int MAXN = 5000;

vector<vector<char>> a(MAXN, vector<char>(MAXN, '?'));
vector<vector<bool>> g(MAXN, vector<bool>(MAXN, false));
queue<pair<int, int>> Q;
map<char, vector<pair<int, int>>> mp;
int n, q, ans = 0;

void bfs() {
    while (Q.size()) {
        auto c = Q.front();
        Q.pop();
        for (auto dps : mp) {
            for (auto dp : dps.s) {
                int nx = c.f - dp.f, ny = c.s - dp.s;
                if (nx < 0 || nx >= n) continue;
                if (ny < 0 || ny >= n) continue;
                if (g[nx][ny]) continue;
                if (a[nx][ny] == dps.f) {
                    g[nx][ny] = true;
                    ans++;
                    Q.push({nx, ny});
                }
            }
        }
    }
}

void solve() {
    cin >> n >> q;

    // collect queries
    vector<pair<pair<int, int>, char>> qs(q);
    for (auto &x : qs) {
        cin >> x.f.f >> x.f.s >> x.s;
        x.f.f--, x.f.s--;
    }

    // construct array
    for (auto x : qs) a[x.f.f][x.f.s] = x.s;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // directions
    mp['R'] = {{0, 1}};
    mp['L'] = {{0, -1}};
    mp['D'] = {{1, 0}};
    mp['U'] = {{-1, 0}};
    mp['?'] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // calc init
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            auto dps = mp[a[i][j]];
            for (auto dp : dps) {
                if (i + dp.f >= n || i + dp.f < 0 || j + dp.s >= n ||
                    j + dp.s < 0) {
                    g[i][j] = true;
                    // cout << i << ' ' << j << '\n';
                    ans++;
                    Q.push({i, j});
                    break;
                }
            }
        }
    }
    bfs();

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << g[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << ans << '\n';
    // cout << '\n';

    reverse(qs.begin(), qs.end());
    vector<int> anss;
    int xc = 0;
    for (auto cq : qs) {
        anss.push_back(ans);
        a[cq.f.f][cq.f.s] = '?';
        for (auto dp : mp['?']) {
            int nx = cq.f.f + dp.f, ny = cq.f.s + dp.s;
            if (!g[cq.f.f][cq.f.s] &&
                (nx < 0 || nx >= n || ny < 0 || ny >= n || g[nx][ny])) {
                Q.push(cq.f);
                g[cq.f.f][cq.f.s] = true;
                ans++;
                bfs();
                break;
            }
        }

        if (xc++ > 10) continue;

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << a[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << g[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << ans << '\n';
        // cout << '\n';
    }

    reverse(anss.begin(), anss.end());
    for (auto x : anss) cout << (n * n - x) << '\n';
    // for (auto x : anss) cout << x << ' ';
    // cout << '\n';

    // vector<int> ans;
    // int c = 0;
    // set<pair<int, int>> ckd;
    // while (q--) {
    //     int x, y;
    //     char dir;
    //     cin >> x >> y >> dir;
    //     x--, y--;

    //     int nx = x + mp[dir].f, ny = y + mp[dir].s;
    //     if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
    //         ans.push_back(c);
    //         continue;
    //     }

    //     cout << x << ' ' << y << ' ' << nx << ' ' << ny << '\n';
    //     if (ckd.count(D.find(nx, ny))) {
    //         ckd.erase(D.find(nx, ny));
    //         c += D.size(x, y);
    //         D.join(x, y, nx, ny);
    //         ckd.insert(D.find(x, y));
    //     } else if (D.eq(x, y, nx, ny)) {
    //         c += D.size(x, y);
    //         D.join(x, y, nx, ny);
    //         ckd.insert(D.find(x, y));
    //     } else {
    //         D.join(x, y, nx, ny);
    //     }
    //     for (auto x : ckd) cout << x.f << x.s << '\n';

    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             cout << D.find(i, j).f << D.find(i, j).s << ' ';
    //         }
    //         cout << '\n';
    //     }
    //     cout << '\n';

    //     ans.push_back(c);
    // }

    // for (auto x : ans) cout << x << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}