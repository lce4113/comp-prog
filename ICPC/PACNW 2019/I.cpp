// 2019-2020 ICPC: Pacific Northwest Regionals
// Problem I

#include <bits/stdc++.h>
using namespace std;

vector<int> vis, mt;
vector<vector<int>> adj;

bool alt(int v) {
    // cout << v << ' ';
    if (vis[v]) return 0;
    vis[v] = 1;
    for (auto x : adj[v]) {
        if (mt[x] == -1 || alt(mt[x])) {
            mt[x] = v;
            return 1;
        }
    }
    return 0;
}

int par(string a) {
    int n = a.size(), inv = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            inv += a[i] > a[j];
        }
    }
    return inv % 2;
}

bool sw(string a, string b) {
    int n = a.size(), off = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) off++;
    }
    return off == 2;
}

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    vector<int> ep, op;
    for (int i = 0; i < n; i++) {
        if (par(a[i]))
            op.push_back(i);
        else
            ep.push_back(i);
    }

    int N = ep.size(), K = op.size();
    if (N < K) {
        swap(N, K);
        swap(ep, op);
    }

    // for (auto x : ep) cout << x << ' ';
    // cout << '\n';
    // for (auto x : op) cout << x << ' ';
    // cout << '\n';

    adj.assign(N, {});
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (sw(a[ep[i]], a[op[j]])) adj[i].push_back(j);
        }
    }

    // for (int i = 0; i < N; i++) {
    //     cout << i << ": ";
    //     for (auto y : adj[i]) cout << y << ' ';
    //     cout << '\n';
    // }

    mt.assign(K, -1);
    for (int i = 0; i < N; i++) {
        vis.assign(N, 0);
        alt(i);
        // cout << '\n';
    }

    int ans = n;
    for (auto x : mt) ans -= (x != -1);
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}