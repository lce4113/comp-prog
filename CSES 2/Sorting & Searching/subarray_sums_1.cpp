// CSES Sorting & Searching: Subarray Sums I

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
    int c = 0, l = 0, r = 0, ans = 0;
    while (l < n) {
        if (c > k || r == n) {
            c -= a[l++];
        } else {
            c += a[r++];
        }
        if (c == k) ans++;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}