// CSES Introductory Problems: Two Knights

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int x;
    cin >> x;
    int n = 1;
    for (; n <= x; n++) {
        int ans = (n * n) * (n * n - 1) / 2;
        if (n >= 2) ans -= 4 * (n - 1) * (n - 2);
        cout << ans << '\n';
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}