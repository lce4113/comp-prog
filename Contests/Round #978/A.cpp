#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0, odd = 0;
    for (auto x : a) {
        if (x % 2 == 0) {
            ans += x;
            r -= x / 2;
            continue;
        }
        ans += x - 1;
        r -= x / 2;
        odd++;
    }
    if (odd >= r) {
        ans += r - (odd - r);
        cout << ans << '\n';
    } else {
        ans += odd;
        cout << ans << '\n';
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}