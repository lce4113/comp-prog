// Codeforces Round 953: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b) {
        cout << n * a << '\n';
    } else if (n <= b - a + 1) {
        int ans = b * (b + 1) / 2 - (b - n) * (b - n + 1) / 2;
        cout << ans << '\n';
    } else {
        int ans = b * (b + 1) / 2 - a * (a + 1) / 2;
        ans += a * (n - (b - a));
        cout << ans << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}