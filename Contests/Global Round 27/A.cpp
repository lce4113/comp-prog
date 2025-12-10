#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = (a - c) * 2 * (b - 1) + (b - d) + (a - c);
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}