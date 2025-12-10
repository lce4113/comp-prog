// ICPC Pacific Northwest Regional 2018-19
// Problem E: Cops And Robbers

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, csl, N;
vector<set<int>> adj;
vector<vector<int>> capacity;
vector<int> ps;

int bfs(int s, int t) {
    ps.clear(), ps.assign(N, -1);
    queue<pair<int, int>> Q;
    Q.push({s, 1e18});
    while (Q.size()) {
        auto [c, f] = Q.front();
        // cout << c << ' ' << f << '\n';
        // cout << (c >= n * m ? c - n * m : c) / m << ' '
        //      << (c >= n * m ? c - n * m : c) % m << '\n';
        Q.pop();
        for (auto x : adj[c]) {
            // cout << x << ' ';
            // cout << (x >= n * m ? x - n * m : x) / m << ' '
            //      << (x >= n * m ? x - n * m : x) % m << ' ';
            // cout << capacity[c][x] << ' ' << ps[x] << '\n';
            if (capacity[c][x] == 0 || ps[x] != -1) continue;
            int nf = min(f, capacity[c][x]);
            ps[x] = c;
            Q.push({x, nf});
            if (x == t) return nf;
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int res = 0, flow;
    while ((flow = bfs(s, t))) {
        int c = t;
        vector<vector<char>> arr(n, vector<char>(m, '.'));
        while (c != s) {
            capacity[ps[c]][c] -= flow;
            capacity[c][ps[c]] += flow;
            c = ps[c];
            // cout << c << ' ';
            // int v = c;
            // cout << "(";
            // if (v >= n * m) {
            // v -= n * m;
            // cout << "1 ";
            // }
            // arr[v / m][v % m] = '#';
            // cout << v / m << ' ' << v % m;
            // cout << ") ";
        }
        // cout << '\n';
        // for (auto x : arr) {
        // for (auto y : x) cout << y;
        // cout << '\n';
        // }
        // cout << "flow: " << flow << '\n';
        // cout << '\n';
        res += flow;
    }
    return res;
}

void solve() {
    cin >> n >> m >> csl;
    N = n * m * 2 + 1;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    vector<int> cs(csl);
    for (auto &x : cs) cin >> x;

    adj.assign(N, {});
    capacity.assign(N, vector<int>(N, 0));
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int Bp;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            adj[x * m + y].insert(n * m + x * m + y);
            adj[n * m + x * m + y].insert(x * m + y);
            capacity[x * m + y][n * m + x * m + y] =
                (a[x][y] == '.' ? 1e18
                                : (a[x][y] == 'B' ? 1e18 : cs[a[x][y] - 'a']));
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    adj[n * m + x * m + y].insert(n * m * 2);
                    adj[n * m * 2].insert(n * m * x * m + y);
                    capacity[n * m + x * m + y][n * m * 2] = 1e18;
                    continue;
                }
                if (a[nx][ny] == 'B') {
                    Bp = nx * m + ny;
                    continue;
                }
                adj[n * m + x * m + y].insert(nx * m + ny);
                adj[nx * m + ny].insert(n * m + x * m + y);
                capacity[n * m + x * m + y][nx * m + ny] = 1e18;
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     cout << i << ": ";
    //     for (auto x : adj[i]) cout << x << ' ';
    //     cout << '\n';
    // }

    // cout << "capacity\n";
    // for (int i = 0; i < N; i++) {
    //     cout << i << ": ";
    //     for (int j = 0; j < N; j++) {
    //         cout << j << " = " << capacity[i][j] << ", ";
    //     }
    //     cout << '\n';
    // }

    // cout << Bp << ' ' << n * m * 2 << '\n';
    int ans = maxflow(Bp, n * m * 2);
    // cout << ans << '\n';
    cout << (ans == 1e18 ? -1 : ans) << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
