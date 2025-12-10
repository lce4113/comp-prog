// MITIT Adv Round 2: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a) {
        for (auto &y : x) cin >> y;
    }

    // for (auto x : a) {
    //     for (auto y : x) {
    //         cout << y << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    vector<vector<int>> v3(n, vector<int>(m, 0)), h3(n, vector<int>(m, 0)),
        sq(n, vector<int>(m, 0));
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (x + 2 < n)
                v3[x][y] =
                    (a[x][y] == a[x + 1][y] && a[x + 1][y] == a[x + 2][y]);
            if (y + 2 < m)
                h3[x][y] =
                    (a[x][y] == a[x][y + 1] && a[x][y + 1] == a[x][y + 2]);
            if (x + 1 < n && y + 1 < m)
                sq[x][y] = (a[x][y] == a[x][y + 1] && a[x][y] == a[x + 1][y] &&
                            a[x][y + 1] == a[x + 1][y + 1]);
        }
    }
    // for (auto x : h3) {
    //     for (auto y : x) {
    //         cout << y << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    vector<vector<int>> v3p(n + 1, vector<int>(m + 1, 0)),
        h3p(n + 1, vector<int>(m + 1, 0)), sqp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v3p[i + 1][j + 1] =
                v3p[i][j + 1] + v3p[i + 1][j] - v3p[i][j] + v3[i][j];
            h3p[i + 1][j + 1] =
                h3p[i][j + 1] + h3p[i + 1][j] - h3p[i][j] + h3[i][j];
            sqp[i + 1][j + 1] =
                sqp[i][j + 1] + sqp[i + 1][j] - sqp[i][j] + sq[i][j];
        }
    }
    // for (auto x : h3p) {
    //     for (auto y : x) {
    //         cout << y << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    int q = 0;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x2++, y2++;
        int v3v = (x2 - 2 < x1 ? 0
                               : v3p[x2 - 2][y2] - v3p[x1][y2] -
                                     v3p[x2 - 2][y1] + v3p[x1][y1]);
        int h3v = (y2 - 2 < y1 ? 0
                               : h3p[x2][y2 - 2] - h3p[x1][y2 - 2] -
                                     h3p[x2][y1] + h3p[x1][y1]);
        // cout << h3p[x2][y2] << ' ' << h3p[x1][y2] << ' ' << h3p[x2][y1] << '
        // '
        //      << h3p[x1][y1] << '\n';
        int sqv = (y2 - 1 < y1 || x2 - 1 < x1
                       ? 0
                       : sqp[x2 - 1][y2 - 1] - sqp[x1][y2 - 1] -
                             sqp[x2 - 1][y1] + sqp[x1][y1]);
        if (v3v + h3v + sqv == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}