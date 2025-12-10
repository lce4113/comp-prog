// Codeforces Round 1000: Problem C

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;

    map<int, set<int>> adj;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    set<int> mx1;
    int ans = 1;
    for (auto x : adj) {
        if (x.s.size() > adj[*mx1.begin()].size()) {
            mx1.clear();
            mx1.insert(x.f);
        }
        if (x.s.size() == adj[*mx1.begin()].size()) mx1.insert(x.f);
    }

    int mnc = 1e9, mx1v;
    for (auto x : mx1) {
        int c = 0;
        for (auto y : adj[x]) c += mx1.count(y);
        if (c < mnc) {
            mnc = c;
            mx1v = x;
        }
    }

    ans += adj[mx1v].size() - 1;
    // cout << mx1 << '\n';
    for (auto x : adj[mx1v]) {
        // cout << x << ' ';
        assert(adj[x].count(mx1v));
        adj[x].erase(mx1v);
    }
    adj[mx1v].clear();
    // cout << '\n';

    int mx2 = 1;
    for (auto x : adj) {
        assert(adj.count(mx2));
        if (x.s.size() > adj[mx2].size()) mx2 = x.f;
    }
    ans += adj[mx2].size() - 1;

    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}