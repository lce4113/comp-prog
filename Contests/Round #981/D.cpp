#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pfs(n + 1, 0);

    for (int i = 0; i < n; i++) {
        pfs[i + 1] = pfs[i] + a[i];
    }

    int ans = 0;
    set<int> curr;
    for (int i = 0; i <= n; i++) {
        // for (auto x : curr) cout << x << ' ';
        // cout << '\n';
        if (curr.count(pfs[i])) {
            ans++;
            curr.clear();
        }
        curr.insert(pfs[i]);
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}