// Codeforces Global Round 28: Problem E

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    if (n >= m) {
        cout << "YES\n";
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << j << ' ';
            }
            cout << '\n';
        }
        return;
    }
    if (m >= 2 * n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<vector<int>> a(m, vector<int>(2 * n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2 * n; j += 2) {
            a[i][(i + j) % (2 * n)] = a[i][(i + j + 1) % (2 * n)] = j / 2 + 1;
        }
    }
    for (int j = 0; j < 2 * n; j++) {
        for (int i = 0; i < m; i++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}