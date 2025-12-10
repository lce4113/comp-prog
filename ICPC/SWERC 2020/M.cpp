// SWERC 2020-21: Problem M

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, m;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool cmp(vector<pair<int, int>> &x, vector<pair<int, int>> &y) {
    return *min_element(x.begin(), x.end()) < *min_element(y.begin(), y.end());
}

vector<vector<pair<int, int>>> rs(vector<string> &a) {
    vector<vector<pair<int, int>>> res;
    vector<vector<bool>> vis(n, vector<bool>(m));
    for (int cx = 0; cx < n; cx++) {
        for (int cy = 0; cy < m; cy++) {
            if (vis[cx][cy] || a[cx][cy] == '.') continue;
            // cout << "cx: " << cx << ' ' << cy << '\n';
            res.push_back({});
            queue<pair<int, int>> Q;
            Q.push({cx, cy});
            while (Q.size()) {
                auto [x, y] = Q.front();
                Q.pop();
                res.back().push_back({x, y});
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || a[nx][ny] == '.') continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    sort(res.begin(), res.end(), cmp);
    return res;
}

bool check1(int x, int y, vector<string> &a) {
    if (x >= 0 && y >= 0 && x + 1 < n && y + 1 < m && a[x][y] == '#' &&
        a[x + 1][y + 1] == '#' && a[x + 1][y] == '.' && a[x][y + 1] == '.')
        return 1;
    if (x >= 0 && y >= 0 && x + 1 < n && y + 1 < m && a[x][y] == '.' &&
        a[x + 1][y + 1] == '.' && a[x + 1][y] == '#' && a[x][y + 1] == '#')
        return 1;
    return 0;
}

vector<pair<int, int>> sol(vector<vector<pair<int, int>>> &rs,
                           vector<string> a) {
    int x1 = 0, x2 = n - 1, y1 = 0, y2 = m - 1;
    vector<vector<int>> d(n, vector<int>(m, -1));
    vector<pair<int, int>> res;
    for (auto r : rs) {
        set<pair<int, int>> g(r.begin(), r.end());
        queue<pair<int, int>> Q;
        for (int x = x1; x <= x2; x++) {
            Q.push({x, y1}), d[x][y1] = 0;
            Q.push({x, y2}), d[x][y2] = 0;
        }
        for (int y = y1 + 1; y <= y2 - 1; y++) {
            Q.push({x1, y}), d[x1][y] = 0;
            Q.push({x2, y}), d[x2][y] = 0;
        }
        set<pair<int, pair<int, int>>> ps1, ps2;
        while (Q.size()) {
            auto [x, y] = Q.front();
            Q.pop();
            if (!g.count({x, y})) ps1.insert({-d[x][y], {x, y}});
            if (!(x == x1 || x == x2 || y == y1 || y == y2))
                ps2.insert({-d[x][y], {x, y}});
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < x1 || nx > x2 || ny < y1 || ny > y2) continue;
                if (d[nx][ny] != -1) continue;
                if (a[nx][ny] == '.' && g.count({x, y})) continue;
                Q.push({nx, ny});
                d[nx][ny] = d[x][y] + 1;
            }
        }
        while (ps1.size()) {
            for (auto [dst, p] : ps1) {
                auto [x, y] = p;
                a[x][y] = '#';
                if (check1(x - 1, y - 1, a)) {
                    a[x][y] = '.';
                    continue;
                }
                if (check1(x, y - 1, a)) {
                    a[x][y] = '.';
                    continue;
                }
                if (check1(x - 1, y, a)) {
                    a[x][y] = '.';
                    continue;
                }
                if (check1(x, y, a)) {
                    a[x][y] = '.';
                    continue;
                }
                if ((x - 1 >= 0 && a[x - 1][y] == '#') &&
                    (x + 1 < n && a[x + 1][y] == '#') &&
                    (y - 1 < 0 || a[x][y - 1] == '.') &&
                    (y + 1 >= m || a[x][y + 1] == '.')) {
                    a[x][y] = '.';
                    continue;
                }
                if ((y - 1 >= 0 && a[x][y - 1] == '#') &&
                    (y + 1 < m && a[x][y + 1] == '#') &&
                    (x - 1 < 0 || a[x - 1][y] == '.') &&
                    (x + 1 >= n || a[x + 1][y] == '.')) {
                    a[x][y] = '.';
                    continue;
                }
                ps1.erase({dst, p});
                res.push_back({x, y});
                break;
            }
        }
        while (ps2.size()) {
            for (auto [dst, p] : ps2) {
                auto [x, y] = p;
                if (y + 1 < m && x + 1 < n && a[x][y + 1] == '.' &&
                    a[x + 1][y] == '.' && a[x + 1][y + 1] == '#')
                    continue;
                if (y - 1 >= 0 && x + 1 < n && a[x][y - 1] == '.' &&
                    a[x + 1][y] == '.' && a[x + 1][y - 1] == '#')
                    continue;
                if (x + 1 < m && a[x + 1][y] == '#' &&
                    (y - 1 < 0 || a[x][y - 1] == '.') &&
                    (y + 1 >= m || a[x][y + 1] == '.'))
                    continue;
                a[x][y] = '.';
                ps2.erase({dst, p});
                res.push_back({x, y});
                break;
            }
        }
        x1 += 2, x2 -= 2, y1 += 2, y2 -= 2;
    }
    return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> m >> n;
    vector<string> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    auto r1 = rs(a), r2 = rs(b);
    if (r1.size() != r2.size()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    auto v1 = sol(r1, a);
    auto v2 = sol(r2, b);
    reverse(v2.begin(), v2.end());
    for (auto x : v1) cout << x.f << ' ' << x.s << '\n';
    for (auto x : v2) cout << x.f << ' ' << x.s << '\n';

    for (auto x : v1) {
        a[x.f][x.s] = a[x.f][x.s] == '.' ? '#' : '.';
        for (auto X : a) {
            for (auto Y : X) cout << Y;
            cout << '\n';
        }
        cout << '\n';
    }
    for (auto x : v2) {
        a[x.f][x.s] = a[x.f][x.s] == '.' ? '#' : '.';
        for (auto X : a) {
            for (auto Y : X) cout << Y;
            cout << '\n';
        }
        cout << '\n';
    }
}