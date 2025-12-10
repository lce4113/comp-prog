// Adam Gąsienica‑Samek Contest 1
// Problem H

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

const int MAXN = 1e5;
int n, M, k;
vector<pair<int, int>> adj[MAXN];

bool ch(int m) {
    vector<int> dp(n, 0);
    for (int i = 1; i < 2 * k; i++) {
        vector<int> ndp(n, -1e9);
        for (int j = 0; j < n; j++) {
            for (auto x : adj[j]) {
                ndp[j] = max(ndp[j], dp[x.f] + (x.s >= m) - (x.s < m));
                if (i >= k && ndp[j] > 0) return 1;
            }
        }
        dp = ndp;
    }
    return 0;
}

void solve() {
    cin >> n >> M >> k;

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[v].push_back({u, w});
    }

    int l = 0, r = 1e9 + 1;
    for (int m = (l + r) / 2; r - l > 1; m = (l + r) / 2) {
        if (ch(m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << (l == 0 ? -1 : l) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}