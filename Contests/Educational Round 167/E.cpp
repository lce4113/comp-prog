// Codeforces Educational Round 167
// Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> con(k, vector<int>(n, 0));
    con[1][1] = 1;
    int con_sum = 1;
    for (int i = 2; i < n; i++) {
        con[1][i] = con_sum + 1;
        if (i - 2 >= 0) con[1][i] += MOD - con[1][i - 2];
        con[1][i] %= MOD;
        con_sum += con[1][i], con_sum %= MOD;
    }

    for (int j = 2; j < k; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            con[j][i] = sum;
            if (i - 2 >= 0) con[j][i] += MOD - con[j - 1][i - 2];
            con[j][i] %= MOD;
            sum += con[j - 1][i], sum %= MOD;
        }
    }

    // for (auto x : con) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }

    int ans = 0;
    for (auto x : con[k - 1]) ans += x, ans %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}