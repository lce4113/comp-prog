// Columbia Programming Camp
// Spring 2025 Contest #1
// Problem L

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
    sort(a.begin(), a.end());

    int ans = 1e18;
    for (int l = 0, r = n / 2; r < n; l++, r++) {
        ans = min(ans, a[r] - a[l]);
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}