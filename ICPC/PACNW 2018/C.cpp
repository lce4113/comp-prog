// ICPC Pacific Northwest Regional 2018-19
// Problem C: Contest Setting

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b;
    for (auto &x : a) cin >> x;
    map<int, int> mp;
    for (auto x : a) mp[x]++;
    for (auto x : mp) b.push_back(x.s);
    int N = b.size();
    vector<vector<int>> dp(N + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;
    // for (auto x : b) cout << x << ' ';
    // cout << '\n';
    for (int j = 1; j <= k; j++) {
        int sm = dp[0][j - 1];
        for (int i = 1; i <= N; i++) {
            dp[i][j] = (sm * b[i - 1]) % MOD;
            sm += dp[i][j - 1], sm %= MOD;
        }
    }

    // for (int i = 0; i <= N; i++) {
    //     cout << i << ": ";
    //     for (auto x : dp[i]) cout << x << ' ';
    //     cout << '\n';
    // }

    int ans = 0;
    for (int i = 0; i <= N; i++) ans += dp[i][k], ans %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}