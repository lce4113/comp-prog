// CSES Graph Algorithms: Labyrinth

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

    pair<int, int> A, B;
    vector<string> p = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') A = {i, j};
            if (a[i][j] == 'B') B = {i, j};
            p[i][j] = '.';
        }
    }

    queue<pair<int, int>> Q;
    Q.push(B);
    p[B.f][B.s] = 'U';
    string ds = "RLDU";
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    while (Q.size()) {
        auto [x, y] = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n) continue;
            if (ny < 0 || ny >= m) continue;
            if (p[nx][ny] != '.') continue;
            if (a[nx][ny] == '#') continue;
            Q.push({nx, ny});
            p[nx][ny] = ds[i];
        }
    }
    if (p[A.f][A.s] == '.') {
        cout << "NO\n";
        return;
    }
    string ans;
    while (A != B) {
        auto c = p[A.f][A.s];
        ans += c;
        if (c == 'L')
            A.s--;
        else if (c == 'R')
            A.s++;
        else if (c == 'U')
            A.f--;
        else
            A.f++;
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}