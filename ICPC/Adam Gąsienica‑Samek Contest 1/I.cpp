// Adam Gąsienica‑Samek Contest 1
// Problem I

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> r(n);
    for (auto &x : r) cin >> x;

    vector<vector<int>> bin(n + 1, vector<int>(30));
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < 30; j++) bin[i][j] = i;
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        u = r[u - 1], v = r[v - 1];
        if (u < v) swap(u, v);
        bin[v][0] = max(bin[v][0], u);
    }

    for (int i = 1; i < n + 1; i++) {
        bin[i][0] = max(bin[i - 1][0], bin[i][0]);
    }

    for (int i = 0; i < 30 - 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            bin[j][i + 1] = bin[bin[j][i]][i];
        }
    }

    // for (auto x : bin) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }

    while (q--) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        a = r[a - 1], b = r[b - 1];
        if (a >= b) {
            cout << "0\n";
            continue;
        }
        if (bin[a][29] < b) {
            cout << "-1\n";
            continue;
        }
        int ans = 0;
        for (int i = 29; i >= 0; i--) {
            if (bin[a][i] < b) {
                a = bin[a][i], ans += (1 << i);
            }
        }
        cout << ans + 1 << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}