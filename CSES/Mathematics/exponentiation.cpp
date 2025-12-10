// CSES Mathematics: Exponentiation

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int binexp(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << binexp(a, b) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}