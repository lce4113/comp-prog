// Codeforces Round 1055: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (abs(x1 - x2) == 1 && y1 == y2) {
        if (x1 < x2) {
            cout << x1 + 1 << '\n';
        } else {
            cout << n - x1 + 1 << '\n';
        }
        return;
    }
    if (abs(y1 - y2) == 1 && x1 == x2) {
        if (y1 < y2) {
            cout << y1 + 1 << '\n';
        } else {
            cout << n - y1 + 1 << '\n';
        }
        return;
    }
    int ans = 0;
    if (x1 < x2) ans = max(ans, x2);
    if (x1 > x2) ans = max(ans, n - x2);
    if (y1 < y2) ans = max(ans, y2);
    if (y1 > y2) ans = max(ans, n - y2);
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}