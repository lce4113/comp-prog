// CSES Sorting & Searching: Distinct Values Subarrays 2

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), ans(n);
    for (auto &x : a) cin >> x;

    map<int, int> mp;
    int l = 0, r = 0;
    while (l < n) {
        if (r < n && (mp.count(a[r]) || mp.size() < k)) {
            mp[a[r++]]++;
        } else {
            if (mp[a[l]] == 1)
                mp.erase(a[l++]);
            else
                mp[a[l++]]--;
        }
        if (mp.size() <= k && l < n) ans[l] = max(ans[l], r - l);
    }

    int tot = 0;
    for (auto x : ans) tot += x;
    cout << tot << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}