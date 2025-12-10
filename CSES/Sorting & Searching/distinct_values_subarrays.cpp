// CSES Sorting & Searching: Distinct Values Subarrays

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

    set<int> st;
    vector<int> b(n, 0);
    for (int l = 0, r = 0; l < n;) {
        if (st.count(a[r]) || r == n) {
            st.erase(a[l++]);
        } else {
            st.insert(a[r++]);
        }
        b[l] = max(b[l], r - l);
    }

    int ans = 0;
    for (auto x : b) ans += x;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}