// Codeforces Round 1055: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> po(1, 0);
    for (int i = 0; i < n; i++) {
        int e = 1ll << __lg(a[i] - 1);
        po.push_back(po.back() + (e == a[i] - 1 && a[i] != 2));
    }
    vector<int> pfs(1, 0);
    for (int i = 0; i < n; i++) {
        pfs.push_back(pfs.back() + __lg(a[i] - 1) + 1);
    }
    // for (auto x : po) cout << x << ' ';
    // cout << '\n';
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        int ans = pfs[r] - pfs[l];
        // cout << ans << ' ' << po[r] - po[l] << '\n';
        ans -= (po[r] - po[l] + 1) / 2;
        cout << ans << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}