// CodeForces Round #935: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, m;
    cin >> a >> b >> m;
    int mxa = (m + 1) / a;
    int mxb = (m + 1) / b;
    if (gcd(a, b) == 1) {
        cout << mxa + mxb << '\n';
        return;
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}