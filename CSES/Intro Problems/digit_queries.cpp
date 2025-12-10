// CSES Intro Problems: Digit Queries

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    int i = 1, m = 9;
    while (n > i * m) {
        n -= i * m;
        i++, m *= 10;
    }
    int x = i - ((n - 1) % i + 1);
    n = ceil((long double)n / i);
    while (i > 1) {
        m /= 10, i--;
        n += m;
    }
    // cout << x << ' ' << n << '\n';
    while (x--) n /= 10;
    cout << n % 10 << '\n';
    // cout << n % 10;
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
