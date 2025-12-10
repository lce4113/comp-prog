// CSES Intro Problems: Knight Moves Grid

#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, -1));
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    a[0][0] = 0;
    while (Q.size()) {
        auto [x, y] = Q.front();
        Q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n) continue;
            if (ny < 0 || ny >= n) continue;
            if (a[nx][ny] != -1) continue;
            a[nx][ny] = a[x][y] + 1;
            Q.push({nx, ny});
        }
    }

    for (auto x : a) {
        for (auto y : x) cout << y << ' ';
        cout << '\n';
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
