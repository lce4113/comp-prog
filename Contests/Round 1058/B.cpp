// Codeforces Round 1058: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(n, vector<int>(m));
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    bool sw = m > n;
    if (sw) {
        vector<string> b(m, string(n, '0'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j][i] = a[i][j];
            }
        }
        a = b;
        swap(n, m);
    }

    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(m, vector<int>(m, 1e9)));
    vector<vector<int>> lst(m, vector<int>(m, -1));
    for (int x = 0; x < n; x++) {
        for (int y1 = 0; y1 < m; y1++) {
            for (int y2 = y1 + 1; y2 < m; y2++) {
                if (a[x][y1] == '1' && a[x][y2] == '1') {
                    if (lst[y1][y2] != -1) {
                        int area = (x - lst[y1][y2] + 1) * (y2 - y1 + 1);
                        for (int cx = lst[y1][y2]; cx <= x; cx++) {
                            dp[cx][y1][y2] = min(dp[cx][y1][y2], area);
                        }
                    }
                    lst[y1][y2] = x;
                }
            }
        }
    }

    for (int x = 0; x < n; x++) {
        // cout << "x: " << x << '\n';
        for (int w = m; w >= 2; w--) {
            for (int l = 0; l + w <= m; l++) {
                dp[x][l][l + w - 2] =
                    min(dp[x][l][l + w - 2], dp[x][l][l + w - 1]);
                dp[x][l + 1][l + w - 1] =
                    min(dp[x][l + 1][l + w - 1], dp[x][l][l + w - 1]);
            }
        }
        for (int y = 0; y < m; y++) {
            if (sw) {
                ans[y][x] = dp[x][y][y];
            } else {
                ans[x][y] = dp[x][y][y];
            }
        }
    }
    for (auto x : ans) {
        for (auto y : x) cout << (y == 1e9 ? 0 : y) << ' ';
        cout << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}