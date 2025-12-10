// Codeforces Round 992: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;

void solve() {
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> adj;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> es(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        es[i] = 2 * adj[i].size();
    }
    for (auto x : adj[1]) es[x]--;
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": " << es[i] << '\n';
    // }

    vector<int> P(n + 1, -1);
    queue<int> Q;
    Q.push(1);
    P[1] = 0;
    while (Q.size()) {
        int c = Q.front();
        Q.pop();
        for (auto x : adj[c]) {
            if (P[x] != -1) continue;
            P[x] = c;
            Q.push(x);
        }
    }
    // for (int i = 1; i <= n; i++) cout << P[i] << ' ';
    // cout << '\n';

    while (q--) {
        int v, p;
        cin >> v >> p;
        // cout << v << ' ' << p << '\n';
        v = P[v];
        int ans = 1;
        vector<int> E;
        while (v != 1 && v != 0) {
            ans += es[v], ans %= MOD;
            E.push_back((es[v] - 2 + (P[v] == 1) + MOD) % MOD);
            v = P[P[v]];
        }

        // for (auto x : E) cout << x << ' ';
        // cout << '\n';
        sort(E.rbegin(), E.rend());

        for (int i = 0; i < p && i < (int)E.size(); i++)
            ans += MOD - E[i], ans %= MOD;
        cout << ans << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}