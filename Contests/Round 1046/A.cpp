// Codeforces Round 1046: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
const int INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<int>> ps(n + 1);
    for (int i = 0; i < n; i++) {
        ps[a[i]].push_back(i);
    }
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i] = max(dp[i], i - 1 < 0 ? 0 : dp[i - 1]);
        int p =
            lower_bound(ps[a[i]].begin(), ps[a[i]].end(), i) - ps[a[i]].begin();
        if (p + a[i] - 1 >= ps[a[i]].size()) continue;
        int nxt = ps[a[i]][p + a[i] - 1] + 1;
        if (nxt > n) continue;
        // cout << i << ' ' << nxt << '\n';
        dp[nxt] = max(dp[nxt], dp[i] + a[i]);
    }
    dp[n] = max(dp[n - 1], dp[n]);

    // for (auto x : dp) cout << x << ' ';
    // cout << '\n';

    cout << dp[n] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}