#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int mi = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[mi]) mi = i;
        if (a[i] >= a[mi] && (i + 1) % 2) mi = i;
    }
    if (n % 2 == 1) {
        int ans1 = a[mi] + n / 2 + (mi + 1) % 2;
        int ans2 = n / 2 + 1;
        cout << max(ans1, ans2) << '\n';
        return;
    }
    int ans1 = a[mi] + n / 2;
    cout << ans1 << '\n';
    // vector<int> dp(n, 0);
    // dp[0] = a[0] + 1, dp[1] = a[1] + 1;
    // for (int i = 0; i < n; i++) {
    //     if (i + 2 < n) dp[i + 2] = max(dp[i + 2], dp[i] + a[i + 2] + 1);
    //     if (i + 3 < n) dp[i + 3] = max(dp[i + 3], dp[i] + a[i + 2] + 1);
    // }
    // for (auto x : dp) cout << x << ' ';
    // cout << '\n';
    // cout << dp[n - 1] << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}