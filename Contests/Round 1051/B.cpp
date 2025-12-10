// Codeforces Round 1051: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int ans = reduce(a.begin(), a.end());
    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());
    for (int c = -1, i = 0; i < m; i++) {
        c += b[i];
        if (c >= n) break;
        ans -= a[c];
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}