#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            if (i == 0) {
                cout << "YES\n";
                return;
            }
            if (i == n - 1) {
                cout << "YES\n";
                return;
            }
            if (a[i + 1] == '1' || a[i - 1] == '1') {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}