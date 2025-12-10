// Codeforces Good Bye 2024 Round: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> adj;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<pair<int, int>> Q;
    map<int, int> ds;
    int c1 = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            Q.push({i, 0});
            ds[i] = 0;
            c1++;
        }
    }
    int ans = c1 * (n - c1);
    while (Q.size()) {
        auto c = Q.front();
        Q.pop();
        for (auto x : adj[c.f]) {
            if (ds.count(x)) continue;
            Q.push({x, c.s + 1});
            ds[x] = c.s + 1;
        }
    }

    int c2 = 0, qs = 0;
    for (auto x : ds) {
        c2 += x.s >= 2;
        if (x.s == 1) {
            qs += adj[x.f].size();
            qs--;
        }
    }
    qs -= c1;
    ans += qs * c2;

    cout << ans << '\n';
}

int32_t main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}