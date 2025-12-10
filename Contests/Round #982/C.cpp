#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<pair<int, int>> b;
    for (int i = 0; i < n; i++) {
        b.push_back({a[i] - (n - i), a[i] - (n - i) + i});
    }
    sort(b.rbegin(), b.rend());
    // for (auto x : b) cout << x.first << ' ' << x.second << '\n';
    // cout << '\n';
    map<int, int> dp;
    for (auto x : b) {
        if (x.f < 0) continue;
        // cout << x.f << ' ' << x.s << '\n';
        dp[x.f] = max({dp[x.f], x.s, dp[x.s]});
    }
    // cout << '\n';
    // for (auto x : dp) cout << x.first << ' ' << x.second << '\n';
    cout << dp[0] + n << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}