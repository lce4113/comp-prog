// CodeForces Round #935: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    // cout << b << ' ' << c << '\n';
    if (b % 3 != 0 && c < 3 - (b % 3)) {
        cout << "-1\n";
        return;
    }
    int e = (b + c) / 3;
    int e2 = ((b + c) % 3) > 0;
    cout << a + e + e2 << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}