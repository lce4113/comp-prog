// Codeforces Educational Round 180: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5;

vector<int> dp(MAXN + 1, 1e18);

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "-1\n";
        return;
    }
    cout << dp[n] + 1 << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    dp[1] = 0;
    for (int i = 3; i <= MAXN; i += 2) {
        dp[i] = dp[i - 2] + 1;
        for (int j = 3; j * j <= i; j += 2) {
            if (i % j) continue;
            dp[i] = min(dp[i], dp[i / j] + dp[j]);
        }
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}