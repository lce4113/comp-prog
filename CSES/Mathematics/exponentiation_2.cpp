// CSES Mathematics: Exponentation II

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int binexp(int a, int b, int m) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= m) {
        if (b % 2) res *= a, res %= m;
    }
    return res;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << binexp(a, binexp(b, c, MOD - 1), MOD) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}