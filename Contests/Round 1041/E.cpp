// Codeforces Round 1041: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int n, k;
vector<int> cs, W;
vector<vector<int>> adj;
int ans = 0;

void color(int v, int p) {
    if (cs[v] == 0) cs[v] = cs[p];
    for (auto to : adj[v]) {
        if (to == p) continue;
        color(to, v);
    }
}

set<int> dfs(int v, int p) {
    set<int> C;
    int same = 0;
    int cutie = 0;
    for (auto to : adj[v]) {
        if (to == p) continue;
        set<int> ch = dfs(to, v);
        if (C.size() < ch.size()) swap(ch, C);
        for (auto c : ch) {
            if (c != cs[v] && C.count(c)) cutie++, same = c;
            C.insert(c);
        }
    }
    if (cutie) ans += W[v];
    if (cs[v] == 0) {
        cs[v] = same;
        if (cutie == 1) ans -= W[v];
    }
    if (cs[v] != 0) C.insert(cs[v]);
    return C;
}

void solve() {
    cin >> n >> k;
    adj.assign(n, {});
    cs.assign(n, 0);
    W.assign(n, 0);
    for (auto &x : W) cin >> x;
    for (auto &x : cs) cin >> x;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    if (cs[0] == 0) cs[0] = 1;
    color(0, 0);
    ans = 0;
    dfs(0, 0);
    cout << ans << '\n';
    for (auto x : cs) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}