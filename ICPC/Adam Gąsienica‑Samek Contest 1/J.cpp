// Adam Gąsienica‑Samek Contest 1
// Problem J

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

const int MOD = 998244353;

int mn(set<int> &c, vector<int> &a) {
    auto cn = c.upper_bound(a[0]);
    if (cn == c.end()) return *a.rbegin();
    return *(--lower_bound(a.begin(), a.end(), *cn));
}

void solve() {
    int n;
    cin >> n;
    int N = 0;
    vector<pair<int, int>> b;
    vector<pair<int, int>> all;
    set<int> c;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        N += m;
        vector<int> a(m);
        for (auto &x : a) cin >> x;
        for (auto x : a) all.push_back({x, i});

        sort(a.begin(), a.end());
        int nxt = mn(c, a);
        c.insert(nxt);
        b.push_back({nxt, i});
    }

    vector<int> p(n);
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) p[b[i].s] = i;

    sort(all.begin(), all.end());
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        dp[p[all[i].s] + 1] += dp[p[all[i].s]];
        dp[p[all[i].s] + 1] %= MOD;
    }
    cout << dp[n] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}