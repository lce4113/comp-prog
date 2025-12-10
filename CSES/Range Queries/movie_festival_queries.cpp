// CSES Range Queries: Movie Festival Queries

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

const int MAXB = 20;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.f >> x.s;

    sort(a.begin(), a.end());

    vector<int> pfs_min(n);
    pfs_min[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        pfs_min[i] = pfs_min[i + 1];
        if (a[i].s < a[pfs_min[i]].s) pfs_min[i] = i;
    }

    vector<vector<int>> bin(n, vector<int>(MAXB + 1));
    for (int i = 0; i < n; i++) {
        int pos =
            lower_bound(a.begin(), a.end(), make_pair(a[i].s, 0)) - a.begin();
        bin[i][0] = pos == n ? n : pfs_min[pos];
    }

    for (int j = 1; j <= MAXB; j++) {
        for (int i = 0; i < n; i++) {
            bin[i][j] = bin[i][j - 1] == n ? n : bin[bin[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int pos = lower_bound(a.begin(), a.end(), make_pair(l, 0)) - a.begin();
        if (pos == n || a[pfs_min[pos]].s > r) {
            cout << "0\n";
            continue;
        }
        int c = pfs_min[pos];
        int ans = 1;
        for (int i = MAXB; i >= 0; i--) {
            // cout << "c: " << c << '\n';
            if (bin[c][i] < n && a[bin[c][i]].s <= r)
                ans += (1 << i), c = bin[c][i];
        }
        cout << ans << '\n';
    }
}