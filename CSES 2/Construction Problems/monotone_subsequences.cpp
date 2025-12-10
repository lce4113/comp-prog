// CSES Construction Problems: Monotone Subsequences

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if (m * m < n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 0; i < n; i += m) {
        for (int j = m; j >= 1; j--) {
            if (i + j <= n) cout << i + j << ' ';
        }
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}