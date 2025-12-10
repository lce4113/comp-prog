// CSES Dynamic Programming: Projects

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    set<int> st;
    vector<array<int, 3>> ps;
    for (int i = 0; i < n; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        st.insert(l), st.insert(r);
        ps.push_back({r, l, w});
    }
    int N = 1;
    map<int, int> mp;
    for (auto x : st) mp[x] = N++;
    for (auto &x : ps) x[0] = mp[x[0]], x[1] = mp[x[1]];
    sort(ps.begin(), ps.end());

    vector<int> dp(N + 1);
    for (int i = 1, c = 0; i <= N; i++) {
        dp[i] = max(dp[i - 1], dp[i]);
        while (c < n && i == ps[c][0]) {
            dp[i] = max(dp[i], dp[ps[c][1] - 1] + ps[c][2]);
            c++;
        }
    }

    cout << dp[N - 1] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}