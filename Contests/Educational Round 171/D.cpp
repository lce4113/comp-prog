#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pfs(n + 1, 0);
    for (int i = 0; i < n; i++) pfs[i + 1] = pfs[i] + a[i];
    vector<int> pfs1(n + 1, 0);
    for (int i = 0; i < n; i++) pfs1[i + 1] = pfs1[i] + pfs[i + 1];

    vector<int> pfs2(n + 1, 0);
    for (int i = 1; i <= n; i++) pfs2[i] = pfs2[i - 1] + a[n - i] * i;
    vector<int> pfs3(n + 1, 0);
    for (int i = 0; i < n; i++) pfs3[i + 1] = pfs3[i] + pfs2[n - i];

    vector<int> ls(1, 0);
    int pos = 0;
    for (int i = n; i > 0; i--) ls.push_back(pos += i);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto itr = --upper_bound(ls.begin(), ls.end(), r);
        auto itl = lower_bound(ls.begin(), ls.end(), l - 1);
        int rc = itr - ls.begin();
        int lc = itl - ls.begin();
        int ans = pfs3[rc] - pfs3[lc];
        // left
        int num = ls[lc] - l + 1;
        if (num != 0) {
            int miss = l - ls[lc - 1] - 1;
            ans += pfs2[num - 1];
            ans += (pfs[lc + miss] - pfs[lc - 1]) * num;
        }
        // right
        num = r - ls[rc];
        if (num != 0) {
            ans += pfs1[rc + num] - pfs1[rc];
            ans -= pfs[rc] * num;
        }
        cout << ans << '\n';
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}