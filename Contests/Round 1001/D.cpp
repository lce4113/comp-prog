// Codeforces Round 1001: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

map<int, vector<int>> adj;
vector<pair<int, int>> lr;

int aim(int goal, pair<int, int> es) {
    if (goal >= es.f && goal <= es.s) return goal;
    if (goal > es.s) return es.s;
    return es.f;
}
pair<int, int> rec(int c, int p) {
    if (c != 1 && adj[c].size() == 1) return {lr[c - 1].f, 0};
    vector<pair<int, int>> cs;
    int goal = -1;
    for (auto x : adj[c]) {
        if (x == p) continue;
        cs.push_back(rec(x, c));
        goal = max(goal, cs.back().f);
    }
    int ans = aim(goal, lr[c - 1]), add = 0;
    for (auto x : cs) {
        add += max(0ll, x.f - ans);
        add += x.s;
    }
    return {ans, add};
}

void solve() {
    int n;
    cin >> n;
    lr.clear();
    adj.clear();
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        lr.push_back({l, r});
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto x = rec(1, -1);
    int ans = x.f + x.s;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}