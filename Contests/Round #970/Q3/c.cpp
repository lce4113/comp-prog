// CodeForces Round #970: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int l, r;
    cin >> l >> r;
    int d = r - l;
    int x = sqrt(2 * d);
    if ((x + 1) * (x) / 2 > d) {
        cout << x << '\n';
    } else {
        cout << x + 1 << '\n';
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}