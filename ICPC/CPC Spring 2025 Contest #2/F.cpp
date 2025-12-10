// Spring 2025 Columbia University Local Contest
// Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), d(n - 2);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n - 2; i++) {
        if (a[i] < a[i + 1] && a[i + 1] > a[i + 2]) d[i] = 1;
        if (a[i] > a[i + 1] && a[i + 1] < a[i + 2]) d[i] = 1;
    }
    int ans = -1;
    for (int c = 0, l = 0, r = 0; r <= n - 2;) {
        // cout << k << ' ' << l << ' ' << r << '\n';
        if (c <= k) {
            ans = max(ans, r - l);
            if (r < n - 2) c += d[r];
            r++;
        } else {
            if (l < n - 2) c -= d[l];
            l++;
        }
    }
    cout << ans + 2 << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}