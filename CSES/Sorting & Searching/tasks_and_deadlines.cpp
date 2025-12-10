// CSES Sorting & Searching: Tasks and Deadlines

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ans += b;
        c.push_back(a);
    }
    sort(c.begin(), c.end());
    int t = 0;
    for (auto x : c) t += x, ans -= t;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}