// CSES Sorting & Searching: Playlist

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
    map<int, int> mp;
    int dps = 0, ans = 0;
    for (int l = 0, r = 0; r < n;) {
        if (dps) {
            if (mp[a[l]] == 2) dps--;
            mp[a[l++]]--;
        } else {
            if (mp[a[r]] == 1) dps++;
            mp[a[r++]]++;
        }
        if (dps == 0) ans = max(ans, r - l);
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}