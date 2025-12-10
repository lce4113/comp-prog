// Educational Codeforces Round 179: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b;
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    b = a;
    sort(b.rbegin(), b.rend());
    vector<pair<int, int>> c;
    for (int i = 0; i < m; i++) {
        c.push_back({abs(a[i] / 100 - b[i] / 100), i});
    }
    sort(c.rbegin(), c.rend());

    vector<vector<int>> ans(n, vector<int>(6, 0));
    for (int i = 0; i < 6; i += 2) {
        for (int j = 0; j < n; j++) {
            ans[j][i] = a[c[j].s];
            ans[j][i + 1] = b[c[j].s];
        }
    }

    for (auto x : ans) {
        for (auto y : x) cout << y << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}