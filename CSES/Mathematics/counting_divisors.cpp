// CSES Mathematics: Counting Divisors

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i) continue;
        ans += 1 + (i * i != n);
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}