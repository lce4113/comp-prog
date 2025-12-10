// BAPC 2023: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    // 0 = start, 1 = pass end, 2 = fail end, 3 = study time
    vector<array<int, 4>> a(n);
    for (auto &x : a) {
        for (auto &y : x) cin >> y;
    }

    sort(a.begin(), a.end());
    vector<int> pfs(1, 0);
    for (int i = 0; i < n; i++) {
        pfs.push_back(pfs.back() + a[i][2] - a[i][0]);
    }

    vector<int> dp(n);
    for (int i = 0; i < n; i++) dp[i] = a[i][0] - a[i][3] - pfs[i];
    // for (auto x : dp) cout << x << ' ';
    // cout << '\n';
    int ans = 1;
    while (*max_element(dp.begin(), dp.end()) >= 0) {
        vector<int> ndp(n, -1e18);
        int c = -1e18;
        for (int i = 0; i < n; i++) {
            // dp = max of -> prev dp - curr study time
            // + diff between curr start and prev end
            // - pfs of failed exams in between
            // dp = total free time if we select curr exam
            ndp[i] = c - a[i][3] + a[i][0] - pfs[i];
            if (dp[i] >= 0) c = max(c, dp[i] - a[i][1] + pfs[i + 1]);
        }
        swap(dp, ndp);
        // for (auto x : dp) cout << x << ' ';
        // cout << '\n';
        ans++;
    }
    cout << ans - 1 << '\n';
}