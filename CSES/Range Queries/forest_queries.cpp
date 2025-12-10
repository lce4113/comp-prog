// CSES Range Queries: Forest Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> pfs(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pfs[i][j] = pfs[i][j - 1] + pfs[i - 1][j] - pfs[i - 1][j - 1] +
                        (a[i - 1][j - 1] == '*');
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--;
        int ans = pfs[x2][y2] - pfs[x2][y1] - pfs[x1][y2] + pfs[x1][y1];
        cout << ans << '\n';
    }
}