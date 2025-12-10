// Codeforces Good Bye 2024 Round: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int cnt(vector<vector<int>> a) {
    map<int, int> mp, mpn;
    int ans = 0;
    for (auto x : a) {
        mpn.clear();
        for (auto y : x) {
            if (y == -1) continue;
            mpn[y]++;
        }
        for (auto y : mpn) ans += y.s * mp[y.f];
        mp = mpn;
    }
    return ans;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a) {
        for (auto &y : x) {
            cin >> y;
            if (y != -1) y--;
        }
    }

    vector<map<int, int>> mp(n);
    for (int i = 0; i < n; i++) {
        for (auto x : a[i]) mp[i][x]++;
    }

    // for (auto x : mp) {
    //     for (auto y : x) {
    //         cout << y.f << ": " << y.s << ", ";
    //     }
    //     cout << '\n';
    // }

    vector<int> dp(k, 0);
    for (int i = 1; i < n; i++) {
        vector<int> ndp(k, 0);

        set<int> nz;
        for (auto x : mp[i]) nz.insert(x.f);
        for (auto x : mp[i - 1]) nz.insert(x.f);

        for (int j = 0; j < k; j++) {
            if (!nz.count(j)) {
                ndp[j] = max(ndp[j], c);
                continue;
            }

            for (int l = 0; l < k; l++) {
                int c = dp[l];
                c += mp[i - 1][j] * mp[i][-1];
                c += mp[i][l] * mp[i - 1][-1];
                // cout << i << ' ' << j << ' ' << l << ' ' << c << '\n';
                ndp[j] = max(ndp[j], c);
            }

            int c = dp[j];
            c += mp[i - 1][j] * mp[i][-1];
            c += mp[i][j] * mp[i - 1][-1];
            c += mp[i][-1] * mp[i - 1][-1];
            ndp[j] = max(ndp[j], c);
        }

        dp = ndp;
        // for (auto x : dp) cout << x << ' ';
        // cout << '\n';
    }
    int ans = -1;
    for (auto x : dp) ans = max(ans, x);
    cout << ans + cnt(a) << '\n';
}

int32_t main() {
    // vector<vector<int>> a = {{-1, -1, 5, -1, -1, -1}, {-1, -1, -1, -1, 2,
    // -1},
    //                          {-1, 1, 3, 3, -1, -1},   {-1, 1, -1, -1, -1, 4},
    //                          {4, 2, -1, -1, -1, 4},   {-1, -1, 1, 2, -1,
    //                          -1}};
    // vector<vector<int>> b = {{4, 4, 5, 4, 4, 4}, {4, 4, 4, 4, 2, 4},
    //                          {4, 1, 3, 3, 4, 4}, {4, 1, 4, 4, 4, 4},
    //                          {4, 2, 4, 4, 4, 4}, {4, 4, 1, 2, 4, 4}};
    // cout << cnt(b) << '\n';
    int t = 1;
    cin >> t;
    while (t--) solve();
}