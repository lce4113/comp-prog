// CSES Sorting & Searching: Subarray Divisibility

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), md(n, 0);
    for (auto &x : a) cin >> x;
    int c = 0, ans = 0;
    md[c]++;
    for (int i = 0; i < n; i++) {
        c += a[i] % n + n, c %= n;
        ans += md[c];
        md[c]++;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}