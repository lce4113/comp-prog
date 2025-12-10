// Codeforces Round 955: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n), pfs(1, 0);
    for (auto &x : a) cin >> x;
    for (auto x : a) pfs.push_back(pfs.back() + x);

    // for (auto x : pfs) cout << x << ' ';
    // cout << '\n';

    vector<int> dp(n + 1, 0);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        auto ub = upper_bound(pfs.begin(), pfs.end(), pfs[i + 1] - l);
        if (ub == pfs.begin()) continue;
        int p = --ub - pfs.begin();
        dp[i + 1] = dp[p] + ((pfs[i + 1] - pfs[p]) <= r);
        // cout << mx << ' ' << dp[i] << '\n';
        dp[i + 1] = max(dp[i + 1], mx);
        mx = max(dp[i + 1], mx);
    }

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