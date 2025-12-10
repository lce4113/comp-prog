// NWERC 2024: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 6e5;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    int hf = reduce(a.begin(), a.end()) / 2;
    // cout << hf << '\n';

    vector<int> dp(MAXN + 1);
    dp[0] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = MAXN - a[i]; j >= 0; j--) {
            dp[j + a[i]] += dp[j];
            if (j + a[i] > hf && j <= hf) {
                ans += dp[j];
                // cout << a[i] << ' ' << j + a[i] << ' ' << dp[j + a[i]] <<
                // '\n';
            }
        }
        // for (int j = 0; j < 20; j++) cout << dp[j] << ' ';
        // cout << '\n';
    }
    cout << ans << '\n';
}