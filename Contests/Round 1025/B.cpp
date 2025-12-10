// Codeforces Round 1025: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n == 1 && m == 1) {
        cout << "0\n";
        return;
    }
    int _n = n, _m = m;

    int ans1 = 1;
    n = n - max(a - 1, n - a);
    while (n != 1) {
        n -= n / 2;
        ans1++;
    }
    while (m != 1) {
        m -= m / 2;
        ans1++;
    }
    m = m - max(b - 1, m - b);

    int ans2 = 1;
    n = _n, m = _m;
    m = m - max(b - 1, m - b);
    while (n != 1) {
        n -= n / 2;
        ans2++;
    }
    while (m != 1) {
        m -= m / 2;
        ans2++;
    }

    cout << min(ans1, ans2) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}