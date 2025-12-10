// CSES Intro Problems: Coin Piles

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if ((a + b) % 3) {
        cout << "NO\n";
        return;
    }
    if (a > b * 2 || b > a * 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
