// Codeforces Pinely Round 5: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);
    vector<int> dp(1, 0), mn(1, 0), ci(1, n);
    for (int i = 1; i <= n - 1; i++) {
        int len = mp[i].size() + mp[i + 1].size();
        vector<int> ndp(len + 1), nmn(len + 1), ni(len + 1);
        int p1 = 0, p2 = 0, c = 0;
        while (p1 < mp[i].size() && p2 < mp[i + 1].size()) {
            if (mp[i][p1] < mp[i + 1][p2]) {
                int r3 = p1, r4 = mp[i + 1].size() - p2;
                int p =
                    lower_bound(ci.begin(), ci.end(), mp[i][p1]) - ci.begin();
                ndp[c] = min(dp[0], mn[p] + r3) + r4;
                ni[c] = mp[i][p1];
                p1++;
            } else {
                int r3 = p1, r4 = mp[i + 1].size() - p2 - 1;
                int p =
                    lower_bound(ci.begin(), ci.end(), mp[i][p2]) - ci.begin();
                ndp[c] = min(dp[0], mn[p] + r3) + r4;
                ni[c] = mp[i + 1][p2];
                p2++;
            }
            c++;
        }
        while (p1 < mp[i].size()) {
            int r3 = p1, r4 = mp[i + 1].size() - p2;
            int p = lower_bound(ci.begin(), ci.end(), mp[i][p1]) - ci.begin();
            ndp[c] = min(dp[0], mn[p] + r3) + r4;
            ni[c] = mp[i][p1];
            p1++;
        }
        while (p2 < mp[i + 1].size()) {
            int r3 = p1, r4 = mp[i + 1].size() - p2 - 1;
            int p = lower_bound(ci.begin(), ci.end(), mp[i][p2]) - ci.begin();
            ndp[c] = min(dp[0], mn[p] + r3) + r4;
            ni[c] = mp[i + 1][p2];
            p2++;
        }
        ndp[len] = dp[0];
        nmn[len] = ndp.back();
        ni[len] = n;
        for (int j = len - 1; j >= 0; j--) {
            nmn[j] = min(nmn[j + 1], ndp[j]);
        }

        dp = ndp;
        mn = nmn;
        ci = ni;
        for (auto x : dp) cout << x << ' ';
        cout << '\n';
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}