// Codeforces Round #983: Problem C

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    // for (auto &x : a) cout << x << ' ';
    // cout << '\n';
    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        int x = a[i] + a[i - 1];
        auto it = lower_bound(a.begin(), a.end(), x);
        int r = a.end() - it;
        ans = min(ans, r + i - 1);
        // cout << i << ' ' << x << ' ' << *it << ' ' << r << '\n';
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}