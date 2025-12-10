// Codeforces Round #988: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, m, k;

bool check(map<int, int> mp, int M) {
    vector<pair<int, int>> pn;
    for (auto x : mp) {
        int d = ceil((double)x.s / M);
        if (d > m) continue;
        int r = m - d;
        pn.push_back({max(1ll, x.f - r), 1});
        pn.push_back({x.f + r, -1});
    }
    // cout << M << '\n';
    sort(pn.begin(), pn.end(), [](pair<int, int> a, pair<int, int> b) {
        return (a.f == b.f ? a.s > b.s : a.f < b.f);
    });
    // for (auto x : pn) cout << x.f << ' ' << x.s << '\n';
    int ans = 0, curr = 0;
    for (auto x : pn) curr += x.s, ans = max(ans, curr);
    // cout << ans << '\n' << '\n';
    return (ans >= k);
}

void solve() {
    cin >> n >> m >> k;
    vector<int> h(n), p(n);
    for (auto &x : h) cin >> x;
    for (auto &x : p) cin >> x;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[p[i]] = max(mp[p[i]], h[i]);
    }
    // for (auto x : mp) cout << x.f << ' ' << x.s << '\n';
    int l = 0, r = 1e18, M = (l + r) / 2;
    // check(mp, 2);
    for (; r - l > 1; M = (l + r) / 2) {
        if (check(mp, M)) {
            r = M;
        } else {
            l = M;
        }
    }
    if (r == 1e18) {
        cout << "-1\n";
        return;
    }
    cout << r << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}