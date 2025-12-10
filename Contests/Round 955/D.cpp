// Codeforces Round 955: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a)
        for (auto &y : x) cin >> y;
    vector<vector<char>> cap(n, vector<char>(m));
    for (auto &x : cap)
        for (auto &y : x) cin >> y;

    vector<vector<int>> cap_pfs(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cap_pfs[i][j] = cap_pfs[i][j - 1] + cap_pfs[i - 1][j] -
                            cap_pfs[i - 1][j - 1] + (cap[i - 1][j - 1] - '0');
        }
    }

    int g = -1;
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
            int tot = cap_pfs[i + k][j + k] - cap_pfs[i + k][j] -
                      cap_pfs[i][j + k] + cap_pfs[i][j];
            int c = abs(tot - (k * k - tot));
            if (c == 0) continue;
            g = g == -1 ? c : gcd(g, c);
        }
    }

    int sm = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cap[i][j] == '0') sm -= a[i][j];
            if (cap[i][j] == '1') sm += a[i][j];
        }
    }
    sm = abs(sm);

    if (g == -1)
        cout << (sm == 0 ? "YES\n" : "NO\n");
    else
        cout << (sm % g == 0 ? "YES\n" : "NO\n");
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}