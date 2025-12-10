// Codeforces Round 1018: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n;
const int INF = 1e18;

int calc_f(pair<int, int> prev, array<bool, 3> d) {
    if (d[1] && d[2]) return INF;
    if (d[2]) return prev.f;
    if (d[1]) return prev.s;
    return min(prev.f, prev.s);
}

int calc_s(pair<int, int> prev, array<bool, 3> d, int cst) {
    if (d[1] && d[0]) return INF;
    if (d[0]) return min(prev.s + cst, INF);
    if (d[1]) return min(prev.f + cst, INF);
    return min(min(prev.f, prev.s) + cst, INF);
}

int cnt(vector<vector<int>> a, vector<int> cst) {
    vector<array<bool, 3>> d(n - 1);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(a[i + 1][j] - a[i][j]) > 1) continue;
            d[i][a[i + 1][j] - a[i][j] + 1] = 1;
        }
    }
    vector<pair<int, int>> dp(n, {INF, INF});
    dp[0] = {0, cst[0]};
    for (int i = 1; i < n; i++) {
        dp[i] = {calc_f(dp[i - 1], d[i - 1]),
                 calc_s(dp[i - 1], d[i - 1], cst[i])};
    }
    return min(dp[n - 1].f, dp[n - 1].s);
}

void solve() {
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b;
    vector<int> c1(n), c2(n);
    for (auto &x : a)
        for (auto &y : x) cin >> y;
    for (auto &x : c1) cin >> x;
    for (auto &x : c2) cin >> x;
    b = a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[j][i] = a[i][j];
        }
    }

    int a1 = cnt(a, c1), a2 = cnt(b, c2);
    if (a1 == 1e18 || a2 == 1e18) {
        cout << "-1\n";
        return;
    }
    cout << a1 + a2 << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
