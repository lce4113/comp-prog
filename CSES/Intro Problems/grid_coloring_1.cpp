// CSES Intro Problems: Grid Coloring I

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A' || a[i][j] == 'B') {
                a[i][j] = ((i + j) % 2 ? 'C' : 'D');
            } else {
                a[i][j] = ((i + j) % 2 ? 'A' : 'B');
            }
        }
    }

    for (auto x : a) cout << x << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
