#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n % 2) {
        cout << "Kosuke\n";
    } else {
        cout << "Sakurako\n";
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}