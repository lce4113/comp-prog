// CSES Dynamic Programming: Movie Festival II

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<int> dp(k + 1);
    dp[0] = 0;
    for (int j = 0; j < n; j++) {
        for (int i = k; i >= a[j]; i--) {
            dp[i] = max(dp[i], dp[i - a[j]] + b[j]);
        }
    }
    cout << dp[k] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}