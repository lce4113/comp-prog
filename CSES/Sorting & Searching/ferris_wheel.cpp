#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, y;
    cin >> n >> y;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int l = 0, r = n - 1; r >= l; r--) {
        // cout << a[l] << ' ' << a[r] << '\n';
        if (a[l] + a[r] <= y) l++;
        ans++;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}