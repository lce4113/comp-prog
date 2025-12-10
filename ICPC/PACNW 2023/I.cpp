// ICPC Pacific Northwest 2023: Problem I

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a{0};
    while (n--) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    n = a.size();

    int dp[n + 1][n + 1];
    for (auto &x : dp[0]) x = 0;
    for (auto &x : dp[1]) x = 0;
    for (int len = 2; len <= n; len++) {
        // cout << len << '\n';
        for (int l = 0; l + len <= n; l++) {
            dp[len][l] = 1e9;
            // cout << "l: " << l << ' ' << len << '\n';
            for (int i = l + 1; i < l + len; i++) {
                int l1 = l, r1 = i, l2 = i, r2 = l + len;
                // cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
                int c = dp[r1 - l1][l1] + dp[r2 - l2][l2] + (a[l] != a[l2]);
                dp[len][l] = min(dp[len][l], c);
            }
            // cout << "dp: " << dp[len][l] << '\n' << '\n';
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; i + j <= n; j++) {
    //         cout << "nums: ";
    //         for (int k = i; k < i + j; k++) cout << a[k];
    //         cout << '\n';
    //         cout << dp[j][i] << '\n';
    //     }
    // }

    cout << dp[n][0] << '\n';
}
