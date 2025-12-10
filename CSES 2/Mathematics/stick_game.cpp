// CSES Mathematics: Stick Game

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> mv(k);
    for (auto &x : mv) cin >> x;
    sort(mv.begin(), mv.end());
    string dp(n + 1, '.');
    dp[0] = 'L';
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k && i - mv[j] >= 0; j++) {
            if (dp[i - mv[j]] == 'L') dp[i] = 'W';
        }
        dp[i] = dp[i] == 'W' ? 'W' : 'L';
    }
    cout << dp.substr(1) << '\n';
}