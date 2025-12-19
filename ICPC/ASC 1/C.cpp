// ASC 1: Problem C

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second

vector<vector<int>> ch;
vector<int> ans, mt;
vector<vector<int>> g;
const int INF = 1e8;

// active, not active
pair<int, int> dfs(int v) {
    if (g[v].size() == 0) return {-INF, 0};
    pair<int, int> res = {0, 0};
    int mn = INF, use = INF;
    // for (auto to : g[v]) cout << to << ' ';
    // cout << '\n';
    for (auto to : g[v]) {
        auto p = dfs(to);
        res.s += max(p.f, p.s);
        if (p.f - p.s < use) use = p.f - p.s, mt[v] = to;
        if (p.f > p.s) {
            if (p.f - p.s < mn) mn = p.f - p.s;
            ch[v].push_back(to);
        }
    }
    mn = max(mn, -INF);
    // cout << "ch " << v << ": ";
    // for (auto x : ch[v]) cout << x << ' ';
    // cout << '\n';
    sort(ch[v].begin(), ch[v].end());
    res.f = res.s + 1;
    if (ch[v].size() == g[v].size()) {
        res.f -= mn;
    }
    // cout << "res: " << v << ' ' << res.f << ' ' << res.s << '\n';
    return res;
}

void pr(int v, bool fir) {
    // cout << v << ' ' << fir << '\n';
    if (fir) ans.push_back(mt[v]);
    for (int i = 0, j = 0; i < g[v].size(); i++) {
        if (j < ch[v].size() && g[v][i] == ch[v][j]) {
            pr(g[v][i], mt[v] != g[v][i]);
            j++;
        } else {
            pr(g[v][i], 0);
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

#ifdef ONLINE_JUDGE
    freopen("grant.in", "r", stdin);
    freopen("grant.out", "w", stdout);
#endif

    int n;
    cin >> n;
    g.assign(n, {});
    mt.assign(n, -1);
    ch.assign(n, {});
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        g[x - 1].push_back(i);
    }
    for (auto &v : g) sort(v.begin(), v.end());
    auto res = dfs(0);
    // cout << "res: " << res.f << ' ' << res.s << '\n';
    if (res.f > res.s)
        pr(0, 1);
    else
        pr(0, 0);
    sort(ans.begin(), ans.end());
    cout << ans.size() * 1000 << '\n';
    for (auto x : ans) cout << x + 1 << ' ';
    cout << '\n';
}
