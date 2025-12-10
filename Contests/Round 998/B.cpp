// Codeforces Round 998: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a)
        for (auto &y : x) cin >> y;
    for (auto &x : a) sort(x.begin(), x.end());

    vector<pair<int, int>> ps;
    for (int j = 0; j < n; j++) ps.push_back({a[j][0], j + 1});
    sort(ps.begin(), ps.end());

    vector<int> as;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) as.push_back(a[ps[j].s - 1][i]);
    }
    // for (auto x : as) cout << x << ' ';
    // cout << '\n';

    for (int i = 1; i < (int)as.size(); i++) {
        if (as[i - 1] > as[i]) {
            cout << "-1\n";
            return;
        }
    }

    for (auto x : ps) cout << x.s << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}