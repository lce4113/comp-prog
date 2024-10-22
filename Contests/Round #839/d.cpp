// CodeForces Round #970: Problem D

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    double mn = 0, mx = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        double b = a[i], c = a[i + 1], d = (double)(b + c) / 2;
        if (b > c) {
            mn = max(mn, d);
        } else if (b < c) {
            mx = min(mx, d);
        }
    }
    // cout << mn << ' ' << mx << '\n';
    int mnn = ceil(mn);
    int mxx = (int)(mx);
    // cout << mn << ' ' << mx << '\n';
    if (mnn > mxx) {
        cout << "-1\n";
    } else {
        cout << mnn << '\n';
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}