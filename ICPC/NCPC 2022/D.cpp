#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n;
    cin >> n;
    int mn = LLONG_MAX, mx, my;
    for (int i = 0; i <= n; i++) {
        int y = floor(sqrt(n * n - i * i)) + 1;
        // if (i == 57450) {
        //     cout << i << ' ' << y << '\n';
        //     cout << i * i + y * y << ' ' << mn << '\n';
        // }
        if (i * i + y * y < mn) {
            mn = i * i + y * y;
            mx = i, my = y;
        }
    }
    cout << mx << ' ' << my << '\n';
}