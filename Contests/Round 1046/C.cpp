// Codeforces Round 1046: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
const int INF = 1e18;
const int MAXN = 2e5;
const int MOD = 998244353;

vector<set<int>> g;
vector<pair<int, int>> bridges;
vector<int> low, num;
vector<bool> vis;
vector<int> dst;
vector<int> vals;
int timer;
int n, m, V;
int ans;

void dfs(int v, int p) {
    // cout << v << ' ' << p << '\n';
    vis[v] = 1;
    low[v] = num[v] = timer++;
    for (auto to : g[v]) {
        if (to == p) continue;
        // cout << v << ' ' << to << '\n';
        if (vis[to]) {
            low[v] = min(low[v], num[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            // cout << v << ' ' << low[to] << ' ' << num[v] << '\n';
            if (low[to] > num[v]) {
                // cout << v << ' ' << to << '\n';
                bridges.push_back({v, to});
            }
        }
    }
}

bool bfs(int r) {
    queue<int> Q;
    Q.push(r);
    dst[r] = 0;
    vis[r] = 1;
    bool bip = 1;
    set<int> all;
    while (Q.size()) {
        auto v = Q.front();
        Q.pop();
        all.insert(vals[v]);
        for (auto to : g[v]) {
            if (vis[to]) {
                if (dst[to] % 2 == dst[v] % 2) bip = 0;
                continue;
            }
            dst[to] = dst[v] + 1;
            vis[to] = 1;
            Q.push(to);
        }
    }
    // cout << "bip: " << bip << '\n';
    bool neg = all.count(-1);
    all.erase(-1);
    if (all.size() > 1) return 1;
    if (!bip) {
        if (*all.begin() != 0) return 1;
    } else {
        if (all.size() == 0) {
            ans = ans * V % MOD;
        }
    }
    return 0;
}

void solve() {
    cin >> n >> m >> V;
    g.assign(n, {});
    bridges.clear();
    low.assign(n, 0);
    num.assign(n, 0);
    vis.assign(n, 0);
    dst.assign(n, 0);
    vals.assign(n, 0);
    timer = 0;
    ans = 1;

    for (auto &x : vals) cin >> x;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].insert(v);
        g[v].insert(u);
    }

    dfs(0, 0);
    for (auto [v, to] : bridges) {
        g[v].erase(to);
        g[to].erase(v);
    }

    // for (int v = 0; v < n; v++) {
    //     cout << v << ": ";
    //     for (auto to : g[v]) cout << to << ' ';
    //     cout << '\n';
    // }

    vis.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (bfs(i)) {
            cout << "0\n";
            return;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}