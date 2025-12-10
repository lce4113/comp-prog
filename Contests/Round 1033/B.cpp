// Codeforces Round 1033: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while (n--) {
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;
        if (x + y == k && dx * dy == -1 || x - y == 0 && dx * dy == 1) ans++;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}