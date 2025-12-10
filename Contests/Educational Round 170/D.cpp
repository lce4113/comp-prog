#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    // 0 1 0 2 0 -3 0 -4 0 -5
    // 0
    // 0 0
    // 0 1 1
    // 3 4 3 3
    vector<int> dp(m + 1, 0), dpn(m + 1, 0);
    map<int, int> pos_store, neg_store;
    for (int k = 0, i = 0; k < n; k++, i++) {
        vector<int> pos, neg;
        while (k < n && a[k] != 0) {
            // cout << k << ' ' << a[k] << '\n';
            if (a[k] > 0)
                pos.push_back(a[k]);
            else
                neg.push_back(-a[k]);
            k++;
        }
        // cout << '\n';
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        for (int j = 0; j <= i; j++) {
            int x = upper_bound(pos.begin(), pos.end(), j) - pos.begin();
            int y = upper_bound(neg.begin(), neg.end(), i - j) - neg.begin();
            if (j != i) dpn[j] = max(dpn[j], dp[j] + x + y);
            if (j != 0) dpn[j] = max(dpn[j], dp[j - 1] + x + y);
        }
        for (auto x : pos) pos_store[x]++;
        for (auto x : neg) neg_store[x]++;
        dp = dpn;
    }
    int ans = 0;
    for (auto x : dpn) ans = max(ans, x);
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie();

    int t = 1;
    // cin >> t;
    while (t--) solve();
}