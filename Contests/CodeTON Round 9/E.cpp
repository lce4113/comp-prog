// CodeTON Round 9: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "1\n";
        return;
    }
    vector<int> dp = {2, 0};
    for (int i = 4; i <= n; i++) {
        dp[0] = (dp[0] + dp[1] * i + i - 1) % MOD;
        dp[1] = (dp[1] * i + i - 2) % MOD;
        // cout << dp[0] << ' ' << dp[1] << '\n';
    }
    cout << dp[0] << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}