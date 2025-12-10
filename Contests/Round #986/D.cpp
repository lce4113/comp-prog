// Codeforces Round #986: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(3, vector<int>(n));
    for (auto &x : a) {
        for (auto &y : x) cin >> y;
    }
    int mn[3] = {a[0][n - 1], a[1][n - 1], a[2][n - 1]};
    vector<pair<char, int>> dp[3];
    dp[0].push_back({'q', n});
    dp[1].push_back({'k', n});
    dp[2].push_back({'j', n});
    string cs = "qkj";
    for (int i = n - 2; i >= 1; i--) {
        int use = -1;
        for (int k = 0; k < 3; k++) {
            if (a[k][i] > mn[k]) {
                use = k;
                // cout << use << ' ' << a[k][i] << ' ' << mn[k] << ' ' << i
                //      << '\n';
                break;
            }
        }
        if (use != -1) {
            for (int k = 0; k < 3; k++) {
                if (a[k][i] > mn[k]) continue;
                mn[k] = a[k][i];
                dp[k] = dp[use];
                dp[k].push_back({cs[k], i + 1});
            }
        }
        // for (auto x : dp) {
        //     for (auto y : x) cout << y.f << ' ' << y.s << '\n';
        //     cout << '\n';
        // }
        // for (auto x : mn) cout << x << ' ';
        // cout << '\n';
    }
    for (int k = 0; k < 3; k++) {
        if (mn[k] < a[k][0]) {
            cout << "YES\n";
            cout << dp[k].size() << '\n';
            for (int i = dp[k].size() - 1; i >= 0; i--) {
                cout << dp[k][i].f << ' ' << dp[k][i].s << '\n';
            }
            return;
        }
    }
    cout << "NO\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
