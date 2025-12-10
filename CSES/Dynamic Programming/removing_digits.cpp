// CSES Sorting & Searching: Removing Digits

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int c = i;
        while (c) {
            dp[i] = min(dp[i], dp[i - c % 10] + 1);
            c /= 10;
        }
    }
    cout << dp[n] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}