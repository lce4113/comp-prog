// Codeforces Round 996: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int col(vector<vector<int>> a, int i) {
    int n = a.size();
    int ans = 0;
    for (int j = 0; j < n; j++) ans += a[j][i];
    return ans;
}

int row(vector<vector<int>> a, int i) {
    int ans = 0;
    for (auto x : a[i]) ans += x;
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    string p;
    cin >> p;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a)
        for (auto &y : x) cin >> y;

    vector<int> rs, cs;
    for (auto x : a) {
        int sm = 0;
        for (auto y : x) sm += y;
        rs.push_back(sm);
    }
    for (int j = 0; j < m; j++) {
        int sm = 0;
        for (int i = 0; i < n; i++) sm += a[i][j];
        cs.push_back(sm);
    }

    // int sm = (p[0] == 'D' ? row(a, 0) : col(a, 0));
    int sm = 0;
    int cx = 0, cy = 0;
    for (auto d : p) {
        // cout << d << '\n';
        // cout << cy << ' ' << cx << '\n';
        if (d == 'D') {
            rs[cy] -= a[cy][cx];
            cs[cx] -= a[cy][cx];
            a[cy][cx] = sm - rs[cy];
            rs[cy] += a[cy][cx];
            cs[cx] += a[cy][cx];
            cy++;
        } else {
            rs[cy] -= a[cy][cx];
            cs[cx] -= a[cy][cx];
            a[cy][cx] = sm - cs[cx];
            rs[cy] += a[cy][cx];
            cs[cx] += a[cy][cx];
            cx++;
        }
        // for (auto x : a) {
        //     for (auto y : x) cout << y << ' ';
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    a[cy][cx] = sm - row(a, cy);

    // cout << row(a, n - 1) << ' ' << col(a, m - 1) << '\n';
    for (auto x : a) {
        for (auto y : x) cout << y << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}