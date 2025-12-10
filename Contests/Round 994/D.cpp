// Codeforces Round 994: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m)), b;
    for (auto &x : a)
        for (auto &y : x) cin >> y;
    // for (auto &x : a) {
    //     for (auto &y : x) cout << y << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';

    vector<int> cs(m, 1e18);
    cs[0] = 0;
    for (int r = 0; r < n; r++) {
        // pfs
        vector<int> ncs(m, 1e18), pfs(1, 0);
        for (auto x : a[r]) pfs.push_back(pfs.back() + x);
        for (int i = 1; i <= m; i++) {
            // get min
            int mn = 1e18, mni;
            vector<int> sms;
            for (int j = 0; j < m; j++) {
                int c;
                if (j + i <= m) {
                    c = pfs[j + i] - pfs[j];
                } else {
                    c = pfs[m] - pfs[j] + pfs[j + i - m];
                }
                // cout << c << ' ' << j << ' ' << k << '\n';
                if (c < mn) mn = c, mni = j;
                sms.push_back(c);
            }
            // cout << i << '\n';
            // cout << "sms: ";
            // for (auto x : sms) cout << x << ' ';
            // cout << '\n';
            int c = mn;
            for (int j = 0, ind = mni; j < m; ind = (ind - 1 + m) % m, j++) {
                // cout << c << " " << sms[ind] << '\n';
                c = min(c, sms[ind]);
                if (ind + i - 1 < m)
                    ncs[ind + i - 1] = min(ncs[ind + i - 1], cs[ind] + c);
                c += k;
            }
            // cout << "ncs: ";
            // for (auto x : ncs) cout << x << ' ';
            // cout << '\n';
        }
        cs = ncs;
    }
    cout << cs[m - 1] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}