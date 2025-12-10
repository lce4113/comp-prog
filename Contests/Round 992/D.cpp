// Codeforces Round 992: Problem D

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

map<int, vector<int>> adj;
map<int, int> cs;

int C(int n, int p) {
    int ans = 1;
    // for (auto x : adj[n]) cout << x << ' ';
    // cout << '\n';
    for (auto x : adj[n]) {
        if (x == p) continue;
        // cout << x << '\n';
        ans += C(x, n);
    }
    cs[n] = ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    adj.clear();
    cs.clear();
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": ";
    //     for (auto y : adj[i]) cout << y << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    C(1, -1);

    // for (int i = 1; i <= n; i++) cout << cs[i] << ' ';
    // cout << '\n';

    vector<int> ans(n, -1);
    vector<bool> vis(n, false);
    stack<pair<int, int>> D;
    D.push({1, 1});
    ans[0] = 1;
    vis[0] = true;
    while (D.size()) {
        auto c = D.top();
        D.pop();
        // cout << c.f << ' ' << c.s << '\n';

        ans[c.f - 1] = c.s;

        // vector<int> cs(1, c.s);
        // for (auto x : adj[c.f]) cs.push_back(cs.back() + 2);
        // cs[1]--;

        int tcs = 2, fir = 1;
        for (auto x : adj[c.f]) {
            if (vis[x - 1]) continue;
            vis[x - 1] = true;
            D.push({x, c.s + tcs - fir});
            tcs += cs[x] * 2;
            if (fir) fir = 0;
        }
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}