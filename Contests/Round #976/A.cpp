#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1)
        cout << n << '\n';
    else {

        int ans = 0;
        while (n > 0) ans += n % k, n /= k;
        cout << ans << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}