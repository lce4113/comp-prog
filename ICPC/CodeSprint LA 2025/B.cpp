#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    map<int, int> mp;
    for (auto x : a) mp[x]++;

    int ml = (k + 1) / 2 * (n / k) - 1, mr = n - (k + 1) / 2;
    set<int> st;
    for (int i = ml; i <= mr; i++) {
        st.insert(a[i]);
    }

    int ans = 0;
    for (auto x : st) ans += mp[x];
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}