// Codeforces Round 1068: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    // f = big, s = sm
    vector<pair<int, int>> dp(n + 1, {0, 0});
    for (int i = 0; i < n; i++) {
        dp[i + 1].f = max(dp[i].f - a[i], b[i] - dp[i].s);
        dp[i + 1].s = min(dp[i].s - a[i], b[i] - dp[i].f);
    }
    cout << dp[n].f << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}