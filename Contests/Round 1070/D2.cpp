// Codeforces Round 1070: Problem D

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

const int B = 85;
const int M = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[v].push_back(u);
    }
    ll ans = m;
    vector<int> mx(n);
    vector<unordered_map<ll, int>> ind(n);
    for (int v = 0; v < n; v++) {
        for (auto to : g[v]) ind[v][a[to]];
        int c = 0;
        for (auto &x : ind[v]) x.s = c++;
        mx[v] = c;
    }
    vector<array<int, 4>> adj;
    for (int v = 0; v < n; v++) {
        for (auto to : g[v]) {
            if (ind[to].count(a[v] - a[to]))
                adj.push_back({v, to, ind[v][a[to]], ind[to][a[v] - a[to]]});
        }
    }
    vector<vector<ll>> dp(n);
    for (int v = 0; v < n; v++) {
        dp[v] = vector<ll>(mx[v]);
        for (auto to : g[v]) dp[v][ind[v][a[to]]]++;
    }
    for (int i = 0; i < B; i++) {
        vector<vector<ll>> ndp(n);
        for (int v = 0; v < n; v++) ndp[v] = vector<ll>(mx[v]);
        for (auto [v, to, ito, prev] : adj) {
            ndp[v][ito] += dp[to][prev], ans += dp[to][prev];
            ndp[v][ito] %= M, ans %= M;
        }
        swap(dp, ndp);
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}