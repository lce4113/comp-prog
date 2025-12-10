// Codeforces Round 984: Problem E

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> a(n, vector<int>(k));
    for (auto &x : a)
        for (auto &y : x) cin >> y;
    vector<vector<int>> sts(k, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            sts[j][i + 1] = sts[j][i] | a[i][j];
        }
    }
    // for (auto &x : sts) {
    //     for (auto &y : x) cout << y << ' ';
    //     cout << '\n';
    // }
    while (q--) {
        int m, L = 1, R = n;
        cin >> m;
        while (m--) {
            int r, c;
            char o;
            cin >> r >> o >> c;
            r--;
            if (o == '<') {
                int lb = --lower_bound(sts[r].begin(), sts[r].end(), c) -
                         sts[r].begin();
                // cout << r << ' ' << o << ' ' << c << ' ' << lb << '\n';
                R = min(R, lb);
            } else {
                int ub = upper_bound(sts[r].begin(), sts[r].end(), c) -
                         sts[r].begin();
                // cout << r << ' ' << o << ' ' << c << ' ' << ub << '\n';
                L = max(L, ub);
            }
            // for (auto x : sts[r]) cout << x << ' ';
            // cout << '\n' << '\n';
        }
        if (L > R) {
            cout << "-1\n";
        } else {
            cout << L << '\n';
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}