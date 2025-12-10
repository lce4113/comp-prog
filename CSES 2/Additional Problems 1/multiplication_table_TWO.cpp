#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int l = n, r = 1e18;
    int num = n * (n / 2) + (n - 1) / 2;
    int ans;
    while (l <= r) {
        int mid = (l + r) / 2, ans2 = 0;
        for (int i = 1; i <= n; i++) {
            ans2 += min(n, (mid / i));
        }
        if (ans2 <= num) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}