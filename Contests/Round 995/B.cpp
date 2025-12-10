// Codeforces Round 995: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = n / (a + b + c) * 3;
    n = n % (a + b + c);
    if (n == 0) {
        cout << ans << '\n';
    } else if (n <= a) {
        cout << ans + 1 << '\n';
    } else if (n <= a + b) {
        cout << ans + 2 << '\n';
    } else if (n <= a + b + c) {
        cout << ans + 3 << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}