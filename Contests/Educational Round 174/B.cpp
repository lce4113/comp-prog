// Codeforces Educational Round 174
// Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a)
        for (auto &y : x) cin >> y;
    map<int, int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!ans.count(a[i][j])) ans[a[i][j]] = 1;
            if (j + 1 < m && a[i][j] == a[i][j + 1]) {
                ans[a[i][j]] = 2;
            }
            if (i + 1 < n && a[i][j] == a[i + 1][j]) {
                ans[a[i][j]] = 2;
            }
        }
    }

    int sm = 0;
    bool ts = false;
    for (auto x : ans) {
        // cout << x.f << ": " << x.s << '\n';
        if (x.s == 2) ts = true;
        sm += x.s;
    }
    cout << sm - (ts ? 2 : 1) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}