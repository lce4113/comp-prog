#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "0\n1\n";
    } else if (n == 2) {
        cout << "2\n1 2\n";
    } else if (n == 3) {
        cout << "2\n1 2 3\n";
    } else if (n == 4) {
        cout << "6\n1 2 3 4\n";
    } else if (n == 5) {
        cout << "5\n2 1 3 4 5\n";
    } else if (n == 6) {
        cout << "7\n1 2 4 6 5 3\n";
    } else if (n == 7) {
        cout << "7\n2 4 5 1 3 6 7\n";
    } else if (n % 2 == 0) {
        int x = pow(2, floor(log2(n)));
        cout << 2 * x - 1 << '\n';
        for (int i = 1; i <= n; i++) {
            if (i == x || i == x - 1 || i == x - 2 || i == 1 || i == 3)
                continue;
            cout << i << ' ';
        }
        cout << 1 << ' ' << 3 << ' ' << x - 2 << ' ' << x - 1 << ' ' << x
             << '\n';
    } else {
        int x = pow(2, floor(log2(n - 1)));
        cout << n << '\n';
        for (int i = 1; i < n; i++) {
            if (i == x || i == x - 1 || i == x - 2 || i == 1 || i == 3)
                continue;
            cout << i << ' ';
        }
        cout << 1 << ' ' << 3 << ' ' << x - 2 << ' ' << x - 1 << ' ' << x << ' '
             << n << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}