// CSES Sorting & Searching: Subarray Sums II

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), pfs(n, 0);
    for (auto &x : a) cin >> x;
    for (auto x : a) pfs.push_back(pfs.back() + x);
    map<int, int> mp;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        // cout << pfs[i] - k << ' ' << mp[pfs[i] - k] << '\n';
        ans += mp[pfs[i] - k];
        mp[pfs[i]]++;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}