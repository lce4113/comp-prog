// Codeforces Round 1007: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<vector<int>> adj;
vector<int> ans;

void rdfs(int st, int sk1, int sk2) {
    // cout << st << ' ' << sk1 << ' ' << sk2 << '\n';
    for (auto x : adj[st]) {
        if (x == sk1 || x == sk2) continue;
        rdfs(x, st, -1);
    }
    ans.push_back(st);
}

void solve() {
    int n, st, en;
    cin >> n >> st >> en;
    st--, en--;

    adj.clear(), adj.assign(n, {});
    ans.clear();

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        // cout << u << ' ' << v << '\n';
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    rdfs(en, -1, -1);

    for (auto x : ans) cout << x + 1 << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}