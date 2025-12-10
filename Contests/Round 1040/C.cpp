// Codeforces Round 1040: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

bool contains(pair<int, int> a, pair<int, int> b) {
    return (b.f >= a.f && b.s <= a.s);
}

void solve() {
    int n;
    cin >> n;
    vector<array<int, 4>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][2];
        a[i][0] = a[i][2] - a[i][1] + 1;
        a[i][3] = i;
    }
    sort(a.rbegin(), a.rend());
    // for (auto x : a) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }
    vector<array<int, 3>> ans;
    for (auto &x : a) {
        bool ok = 1;
        for (auto &y : ans) {
            if (contains({y[1], y[2]}, {x[1], x[2]})) {
                ok = 0;
                break;
            }
        }
        if (ok) ans.push_back({x[3], x[1], x[2]});
    }
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x[0] + 1 << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}