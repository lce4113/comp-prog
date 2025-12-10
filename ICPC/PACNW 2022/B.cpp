// ICPC 2022 Pacific Northwest Regionals
// Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    vector<bool> b;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        b.push_back(a[i] != a[j]);
    }
    // for (auto x : b) cout << x << ' ';
    // cout << '\n';
    int m = b.size();

    if (m == 1) {
        cout << b[0] << '\n';
        return;
    }

    // 00, 01
    vector<pair<int, int>> dp;
    if (b[0] && b[1]) dp.push_back({1, 1});
    if (b[0] && !b[1]) dp.push_back({2, 1});
    if (!b[0] && b[1]) dp.push_back({2, 0});
    if (!b[0] && !b[1]) dp.push_back({0, 2});
    // 00, 01
    // 001, 011 -> 000, 001
    // 000, 010 -> 000, 001
    for (int i = 2; i < m; i++) {
        if (b[i])
            dp.push_back({min(dp.back().f + 2, dp.back().s + 1),
                          min(dp.back().f, dp.back().s + 1)});
        if (!b[i])
            dp.push_back({min(dp.back().f, dp.back().s + 2),
                          min(dp.back().f + 2, dp.back().s + 1)});
    }
    cout << min(dp.back().f, dp.back().s + 1) << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}