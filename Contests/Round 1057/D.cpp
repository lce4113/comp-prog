// Codeforces Round 1057: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int val(int a, int b, int c) {
    vector<int> arr({a, b, c});
    sort(arr.begin(), arr.end());
    return arr[2] - arr[0];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        a.push_back(a[i]);
    }
    int ans = 1e18;
    for (int z = 0; z < 3; z++) {
        vector<int> dp(n);
        dp[0] = 1e18;
        dp[1] = abs(a[z + 1] - a[z]);
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 2] + abs(a[z + i] - a[z + i - 1]),
                        (i == 2 ? 0 : dp[i - 3]) +
                            val(a[z + i - 2], a[z + i - 1], a[z + i]));
        }
        // for (auto x : dp) cout << x << ' ';
        // cout << '\n';
        ans = min(ans, dp[n - 1]);
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}