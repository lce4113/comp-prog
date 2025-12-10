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

    int g = a[0];
    for (auto x : a) g = gcd(g, x);
    for (auto &x : a) x /= g;
    sort(a.rbegin(), a.rend());

    vector<int> dp(a[0] + 1, 1e18);
    for (auto x : a) dp[x] = 1;
    for (int i = a[0]; i >= 1; i--) {
        for (auto x : a) dp[gcd(i, x)] = min(dp[gcd(i, x)], dp[i] + 1);
    }
    if (dp[1] == 1) {
        cout << n - count(a.begin(), a.end(), 1) << '\n';
        return;
    }
    cout << dp[1] - 1 + n - 1 << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}