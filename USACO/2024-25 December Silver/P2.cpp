// USACO 2024-25 December Contest, Silver
// Problem 2. "Deforestation"

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    vector<pair<pair<int, int>, int>> lr(q);
    for (auto &x : lr) cin >> x.f.f >> x.f.s >> x.s;
    sort(lr.begin(), lr.end());

    for (int j = 0; j < q; j++) {
        int L = lower_bound(a.begin(), a.end(), lr[j].f.f) - a.begin();
        int R = upper_bound(a.begin(), a.end(), lr[j].f.s) - a.begin();
        int cnt = R - L;
        lr[j].s = cnt - lr[j].s;
    }

    // for (auto x : lr) cout << x.s << ' ';
    // cout << '\n';

    int ans = 0, c = 0;
    set<pair<int, int>> ends;
    multiset<pair<int, int>> vals;
    map<int, pair<int, int>> mp;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < q && lr[j].f.f <= a[i]) {
            vals.insert({c + lr[j].s, j});
            mp[j] = {c + lr[j].s, j};
            ends.insert({lr[j].f.s + 1, j});
            j++;
        }
        while (ends.size() && a[i] >= ends.begin()->f) {
            vals.erase(mp[ends.begin()->s]);
            ends.erase(*ends.begin());
        }
        // cout << a[i] << ' ' << c << '\n';
        // cout << "v: ";
        // for (auto x : vals) cout << x.f << ',' << x.s << ' ';
        // cout << '\n';
        // cout << "e: ";
        // for (auto x : ends) cout << x.f << ',' << x.s << ' ';
        // cout << '\n' << '\n';
        if (vals.size() == 0 || vals.begin()->f > c) ans++, c++;
    }
    // cout << '\n';

    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
