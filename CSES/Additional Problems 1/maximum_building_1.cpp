// CSES Additional Problems I: Maximum Building I

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<int>> up(n, vector<int>(m));
    for (int i = 0; i < m; i++) up[0][i] = a[0][i] == '*' ? 0 : 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            up[i][j] = a[i][j] == '*' ? 0 : up[i - 1][j] + 1;
        }
    }

    int ans = 0;
    for (auto row : up) {
        vector<int> L(m), R(m);
        stack<pair<int, int>> Q;
        Q.push({-1, -1});
        for (int i = 0; i < m; i++) {
            while (Q.top().f >= row[i]) Q.pop();
            L[i] = Q.top().s;
            Q.push({row[i], i});
        }
        while (Q.size()) Q.pop();
        Q.push({-1, m});
        for (int i = m - 1; i >= 0; i--) {
            while (Q.top().f >= row[i]) Q.pop();
            R[i] = Q.top().s;
            Q.push({row[i], i});
        }
        for (int i = 0; i < m; i++) {
            ans = max(ans, (R[i] - L[i] - 1) * row[i]);
        }
    }

    cout << ans << '\n';
}