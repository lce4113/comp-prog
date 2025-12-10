// Codeforces Round 955: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    x++, k--;
    while (x % y == 0) x /= y;

    while (k > 0 && x > y) {
        int c = (y - x % y) % y;
        x += min(k, c);
        k -= min(k, c);
        while (x % y == 0) x /= y;
    }

    if (k == 0) {
        cout << x << '\n';
        return;
    }
    // cout << x << ' ' << y << ' ' << k << '\n';

    k %= y - 1;
    x += k, x = (x - 1) % (y - 1) + 1;
    cout << x << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}