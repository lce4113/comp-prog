// Codeforces Round #983: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    vector<vector<int>> alg;
    alg.push_back({0, 0, 0});
    alg.push_back({1, 0, 0});
    alg.push_back({0, 1, 0});
    for (int i = 3; i < n; i++) {
        int A = 2 - 2 * alg[i - 1][0] - alg[i - 2][0];
        int B = 1 - 2 * alg[i - 1][1] - alg[i - 2][1];
        int X = a[1] - a[i - 1] - 2 * alg[i - 1][2] - alg[i - 2][2];
        alg.push_back({A, B, X});
    }
    alg[1] = {0, alg[n - 1][1] - 1, alg[n - 1][2] + a[0] - a[1]};

    int B = 2 * alg[1][1] + 1 -
            2 * (alg[n - 1][1] + alg[1][1] * alg[n - 1][0]) -
            (alg[n - 2][1] + alg[1][1] * alg[n - 2][0]);
    int X = a[n - 1] - a[1] - 2 * alg[1][2] +
            2 * (alg[n - 1][2] + alg[1][2] * alg[n - 1][0]) +
            (alg[n - 2][2] + alg[1][2] * alg[n - 2][0]);
    B = X / B;
    int A = alg[1][1] * B + alg[1][2];

    vector<int> ans(n);
    int mn = 1e18;
    for (int i = 0; i < n; i++) {
        ans[i] = alg[i][2] + alg[i][1] * B + alg[i][0] * A;
        mn = min(mn, ans[i]);
    }

    for (auto x : ans) cout << (x - mn) << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}