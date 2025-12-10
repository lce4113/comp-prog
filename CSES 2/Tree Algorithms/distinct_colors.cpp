// CSES Tree Algorithms: Distinct Colors

#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int n;
    vector<vector<int>> a;
    vector<int> f(vector<int> &x, vector<int> &y) {
        vector<int> res(x.size() + y.size());
        merge(x.begin(), x.end(), y.begin(), y.end(), res.begin());
        return res;
    }
    Tree(vector<int> &in) {
        n = in.size(), a.assign(2 * n, {});
        for (int i = 0; i < n; i++) a[i + n] = {in[i]};
        for (int i = n - 1; i >= 0; i--) a[i] = f(a[i * 2], a[i * 2 + 1]);
    }
    int count(vector<int> &x, int k) {
        return x.end() - lower_bound(x.begin(), x.end(), k);
    }
    int q(int l, int r, int k) {
        int ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans += count(a[l++], k);
            if (r % 2) ans += count(a[--r], k);
        }
        return ans;
    }
};

vector<int> tin, tout;
vector<vector<int>> adj;
int timer = 0;

void dfs(int v, int p) {
    tin[v] = timer++;
    for (auto to : adj[v]) {
        if (to == p) continue;
        dfs(to, v);
    }
    tout[v] = timer++;
}

int32_t main() {
    int n;
    cin >> n;
    adj.assign(n, {});
    tin.assign(n, 0);
    tout.assign(n, 0);
    vector<int> vals(n);
    for (auto &x : vals) cin >> x;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    vector<int> V(timer); // asdf
    map<int, set<int>> ps;
    for (int i = 0; i < n; i++) {
        ps[vals[i]].insert(tin[i]);
        // V[tin[i]] = vals[i]; // asdf
    }
    // for (auto x : V) cout << x << ' ';
    // cout << '\n';
    vector<int> nxt(timer);
    for (auto [_, p] : ps) {
        p.insert(timer);
        for (auto it1 = p.begin(), it2 = ++p.begin(); it2 != p.end();
             it1++, it2++)
            nxt[*it1] = *it2;
    }
    Tree seg(nxt);
    // for (auto x : nxt) cout << x << ' ';
    // cout << '\n';
    // for (auto x : seg.a) {
    //     for (auto y : x) {
    //         cout << y << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 0; i < n; i++) {
        cout << seg.q(tin[i], tout[i], tout[i] + 1) << ' ';
    }
    cout << '\n';
}