// CSES Sorting & Searching: Sum of Four Values

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, sm;
    cin >> n >> sm;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            mp[a[i] + a[j]].push_back({i, j});
        }
    }
    for (auto x : mp) {
        for (auto y : x.s) {
            auto c = sm - x.f;
            if (!mp.count(c)) continue;
            int i = 0;
            while (i < mp[c].size() &&
                   (mp[c][i].f == y.f || mp[c][i].f == y.s ||
                    mp[c][i].s == y.f || mp[c][i].s == y.s))
                i++;
            if (i == mp[c].size()) continue;
            cout << y.s + 1 << ' ' << y.f + 1 << ' ' << mp[c][i].f + 1 << ' '
                 << mp[c][i].s + 1 << '\n';
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}