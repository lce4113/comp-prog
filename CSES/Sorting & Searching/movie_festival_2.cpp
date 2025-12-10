// CSES Sorting & Searching: Movie Festival II

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.s >> x.f;
    sort(a.begin(), a.end());
    multiset<int> st;
    for (int i = 0; i < k; i++) st.insert(0);
    int ans = 0;
    for (auto x : a) {
        auto it = st.upper_bound(x.s);
        if (it == st.begin()) continue;
        st.erase(--it);
        st.insert(x.f);
        ans++;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}