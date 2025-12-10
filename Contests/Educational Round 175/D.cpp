// Codeforces Educational Round 175: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> ps(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> ps[i];
        ps[i]--;
    }
    // for (auto x : ps) cout << x << ' ';
    // cout << '\n';
    for (int i = 0; i < n - 1; i++) {
        adj[ps[i]].push_back(i + 1);
        adj[i + 1].push_back(ps[i]);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (auto y : adj[i]) cout << y << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    queue<array<int, 3>> Q;
    Q.push({0, 0, -1});
    vector<int> ds(n, -1);
    int md = 0;
    while (Q.size()) {
        auto [c, d, p] = Q.front();
        Q.pop();
        ds[c] = d;
        md = max(md, d);
        for (auto x : adj[c]) {
            if (x == p) continue;
            Q.push({x, d + 1, c});
        }
    }

    vector<vector<int>> dps(md + 1);
    for (int i = 0; i < n; i++) {
        dps[ds[i]].push_back(i);
    }

    // for (int i = 0; i <= md; i++) {
    //     cout << i << ": ";
    //     for (auto y : dps[i]) cout << y << ' ';
    //     cout << '\n';
    // }

    vector<int> cs(n, 0), smd(md + 1, 0);
    cs[0] = 1, smd[0] = 1;
    for (auto x : adj[0]) cs[x] = 1, smd[1]++;
    for (int i = 2; i <= md; i++) {
        for (auto x : dps[i]) {
            cs[x] = (smd[i - 1] - cs[ps[x - 1]] + MOD) % MOD;
            // cout << x << ' ' << cs[x] << ' ' << ps[x] << ' ' << cs[ps[x]]
            //      << '\n';
            smd[i] += cs[x], smd[i] %= MOD;
        }
    }

    int ans = 0;
    // for (auto x : cs) cout << x << ' ';
    // cout << '\n';
    // for (auto x : smd) cout << x << ' ';
    // cout << '\n';
    for (auto x : smd) {
        // cout << x << ' ';
        ans += x, ans %= MOD;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}