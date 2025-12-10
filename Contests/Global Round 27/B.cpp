#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "-1\n";
    } else if (n == 2) {
        cout << "66\n";
    } else if (n == 3) {
        cout << "-1\n";
    } else if (n % 2) {
        for (int i = 4; i < n; i++) {
            cout << "3";
        }
        cout << "6366" << '\n';
    } else {
        for (int i = 2; i < n; i++) {
            cout << "3";
        }
        cout << "66" << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}