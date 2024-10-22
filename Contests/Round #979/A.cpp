#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int mx = -INT_MAX, mn = INT_MAX;
    for (auto x : a) mx = max(mx, x), mn = min(mn, x);
    if (n == 1)
        cout << 0 << '\n';
    else
        cout << (mx - mn) * (n - 1) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}