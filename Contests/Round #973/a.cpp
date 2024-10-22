// CodeForces Round #973: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    int ans = ceil((double)n / min(x, y));
    cout << ans << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}