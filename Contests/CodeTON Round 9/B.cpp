// CodeTON Round 9: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == a[i]) {
            cout << a[i] << a[i] << '\n';
            return;
        }
        if (i != 1 && a[i] != a[i - 1] && a[i] != a[i - 2] &&
            a[i - 1] != a[i - 2]) {
            cout << a[i - 2] << a[i - 1] << a[i] << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}