// Codeforces Round 995: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (auto &z : a) cin >> z;
    sort(a.begin(), a.end());
    int sm = 0;
    for (auto z : a) sm += z;
    x = sm - x, y = sm - y;
    if (x > y) swap(x, y);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = lower_bound(a.begin(), a.end(), x - a[i]) - a.begin();
        int r = upper_bound(a.begin(), a.end(), y - a[i]) - a.begin();
        // cout << max(a[i], x - a[i]) << ' ' << y - a[i] << ' ' << r - l <<
        // '\n';
        ans += max(0ll, r - max(l, i));
        if (a[i] * 2 >= x && a[i] * 2 <= y) ans--;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}