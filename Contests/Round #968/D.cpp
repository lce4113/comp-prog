// Codeforces Round #968: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ps;
    int mx = 0;
    while (n--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (auto &x : a) cin >> x;
        set<int> b;
        for (auto x : a) b.insert(x);
        int m1 = 0;
        while (b.count(m1)) m1++;
        int m2 = m1 + 1;
        mx = max(m1, mx);
        while (b.count(m2)) m2++;
        ps.push_back({m2, m1});
    }
    map<int, int> dp;

    // DP stuff (find what things map to)
    sort(ps.rbegin(), ps.rend());
    for (auto p : ps) {
        if (dp.count(p.f))
            dp[p.s] = max(dp[p.s], dp[p.f]);
        else
            dp[p.s] = max(dp[p.s], p.f);
    }

    // Find out if u can do max hacks
    sort(ps.begin(), ps.end(),
         [](pair<int, int> a, pair<int, int> b) { return a.s > b.s; });
    for (int i = 1; i < (int)ps.size(); i++) {
        if (ps[i - 1].s == ps[i].s) mx = max(mx, dp[ps[i].s]);
    }

    // Add up ans
    int ans = m * (m + 1) / 2;
    ans -= min(m, mx) * (min(m, mx) + 1) / 2;
    ans += mx * (min(m, mx) + 1);
    for (auto x : dp) {
        if (x.f <= m) {
            if (x.f <= mx) {
                ans -= mx;
            } else {
                ans -= x.f;
            }
            ans += max(x.s, mx);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}