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
    vector<vector<pair<int, int>>> adj(n);
    vector<map<int, vector<int>>> val(n);
    for (int v = 0; v < n; v++) {
        for (int i = 0; i < g[v].size(); i++) {
            val[v][a[g[v][i]]].push_back(i);
        }
    }
    for (int v = 0; v < n; v++) {
        for (int ito = 0; ito < g[v].size(); ito++) {
            int to = g[v][ito];
            if (val[to].count(a[v] - a[to])) {
                for (auto i : val[to][a[v] - a[to]])
                    adj[v].push_back({ito, to, i});
            }
        }
    }
    vector<vector<int>> init(n);
    for (int v = 0; v < n; v++) {
        set<int> c;
        for (auto x : g[v]) c.insert(x);
        init[v] = vector<int>(c.size());
    }
    vector<vector<int>> dp(n);
    for (int v = 0; v < n; v++) {
        for (auto to : g[v]) dp[v][].push_back(1);
    }
    for (int i = 0; i < B; i++) {
        vector<vector<int>> ndp = init;
        for (int v = 0; v < n; v++) {
            for (auto [ito, to, i]) {
                ndp[v][ito] += dp[to][i], ans += ndp[v][ito];
                ndp[v][ito] %= M, ans %= M;
            }
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