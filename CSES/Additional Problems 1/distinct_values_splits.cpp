// CSES Additional Problems I: Distinct Values Splits

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> mp;
    vector<int> lst(n), lst2(n);
    for (int i = 0; i < n; i++) {
        lst[i] = mp.count(a[i]) ? mp[a[i]] : -1;
        mp[a[i]] = i;
        lst2[i] = max(i == 0 ? -1 : lst2[i - 1], lst[i]);
    }
    vector<int> dp(n + 1), dp_pfs(1, 0);
    dp[0] = 1;
    dp_pfs.push_back(dp_pfs.back() + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = (dp_pfs[i] - dp_pfs[lst2[i - 1] + 1] + MOD) % MOD;
        dp_pfs.push_back((dp_pfs.back() + dp[i]) % MOD);
    }

    cout << dp.back() << '\n';
}