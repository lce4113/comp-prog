// ICPC 2022 Pacific Northwest Regionals
// Problem H

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

vector<vector<int>> bin;
vector<vector<int>> adj;
vector<int> tin, tout;
int timer = 0;

void dfs(int r, int p) {
    tin[r] = timer;
    for (auto c : adj[r]) {
        if (c != p) dfs(c, r);
    }
    tout[r] = timer++;
}

bool anc(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }

int lift(int u, int v) {
    for (int i = 29; i >= 0; i--) {
        if (!anc(bin[u][i], v)) u = bin[u][i];
    }
    return u;
}

void solve() {
    int n, m;
    cin >> n >> m;
    bin.assign(n, vector<int>(30, 0));
    adj.assign(n, {});
    tin.assign(n, 0), tout.assign(n, 0);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        bin[b][0] = a;
    }
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 30; j++) {
            bin[i][j] = bin[bin[i][j - 1]][j - 1];
        }
    }

    // for (auto x : bin) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }
    // cout << lift(2, 5) << ' ' << lift(5, 2) << '\n';
    // for (auto x : tin) cout << x << ' ';
    // cout << '\n';
    // for (auto x : tout) cout << x << ' ';
    // cout << '\n';

    vector<int> q(m);
    for (auto &x : q) {
        cin >> x;
        x--;
    }
    int ans = m, lst = q[0];
    for (int i = 1; i < m; i++) {
        // cout << q[i] << ' ' << q[i + 1] << '\n';
        if (anc(q[i], lst)) continue;
        if (anc(lst, q[i])) {
            lst = q[i];
            continue;
        }
        // cout << lst << ' ' << q[i] << '\n';
        if (lift(lst, q[i]) > lift(q[i], lst)) {
            ans = i;
            break;
        }
        lst = q[i];
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}