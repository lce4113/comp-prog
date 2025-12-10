// ICPC Pacific Northwest 2023: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, m;

pair<int, int> find(vector<vector<int>> &a, int num) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == num) return {i, j};
        }
    }
    return {-1, -1};
}

void sor(vector<vector<int>> &a, vector<array<int, 4>> &A, int j) {
    vector<pair<int, int>> bad, spots;
    for (int i = n * j + 1; i <= n * j + n; i++) {
        auto [x, y] = find(a, i);
        if (y != j) bad.push_back({y, x});
    }
    sort(bad.begin(), bad.end());
    for (int i = 0; i < n; i++) {
        if (a[i][j] > n * j + n || a[i][j] < n * j + 1) {
            spots.push_back({i, j});
        }
    }
    // cout << "bad:" << j << "\n";
    // for (auto x : bad) cout << x.s << ' ' << x.f << '\n';
    // cout << "spots:" << j << "\n";
    // for (auto x : spots) cout << x.f << ' ' << x.s << '\n';
    int k = spots.size();
    for (int i = 0; i < k; i++) {
        int x1 = spots[i].f, y1 = spots[i].s, x2 = bad[i].s, y2 = bad[i].f;
        for (int p = 0; p < y2; p++) {
            if (a[x2][p] > a[x1][y1]) {
                A.push_back({x1, y1, x2, p});
                swap(a[x1][y1], a[x2][p]);
            }
        }
        A.push_back({x1, y1, x2, y2});
        swap(a[x1][y1], a[x2][y2]);
    }
    for (int i = n - 1; i >= 0; i--) {
        // cout << i << ' ' << j << ' ' << j * n + i + 1 << '\n';
        auto [x, y] = find(a, j * n + i + 1);
        // cout << x << ' ' << y << '\n';
        if (x == i && y == j) continue;
        A.push_back({i, j, x, y});
        swap(a[i][j], a[x][y]);
    }
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for (auto &x : a)
        for (auto &y : x) cin >> y;
    for (auto &x : b)
        for (auto &y : x) cin >> y;

    vector<array<int, 4>> A, B;
    for (int j = m - 1; j >= 0; j--) {
        sor(a, A, j), sor(b, B, j);
    }
    reverse(B.begin(), B.end());
    cout << A.size() + B.size() << '\n';
    for (auto x : A) {
        for (auto y : x) cout << y + 1 << ' ';
        cout << '\n';
    }
    for (auto x : B) {
        for (auto y : x) cout << y + 1 << ' ';
        cout << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}