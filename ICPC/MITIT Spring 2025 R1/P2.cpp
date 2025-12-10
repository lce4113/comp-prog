// MITIT Spring 2025: Problem 2

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    vector<int> ds;
    for (int i = 1; i < n; i++) {
        ds.push_back(a[i] - a[i - 1]);
    }
    n--;

    vector<int> pm(1, 1e9), sm(1, 1e9);
    for (int i = 0; i < n; i++) {
        pm.push_back(min(pm.back(), ds[i]));
    }
    for (int i = n - 1; i >= 0; i--) {
        sm.push_back(min(sm.back(), ds[i]));
    }
    // for (auto x : pm) cout << x << ' ';
    // cout << '\n';
    // for (auto x : sm) cout << x << ' ';
    // cout << '\n';
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if (i - 1 >= 0) ans = min(ans, ds[i] + pm[i - 1]);
        if (n - 2 - i >= 0) ans = min(ans, ds[i] + sm[n - 2 - i]);
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
