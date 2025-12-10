#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &x : a)
        for (auto &y : x) cin >> y;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (a[i][k] < 0) {
                if (!mp[k - i]) {
                    mp[k - i] = -a[i][k];
                } else {
                    mp[k - i] = max(-a[i][k], mp[k - i]);
                }
            }
        }
    }
    int ans = 0;
    for (auto x : mp) ans += x.second;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}