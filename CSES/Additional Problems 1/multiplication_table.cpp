// CSES Additional Problems I: Multiplication Table

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;

int count(int m) {
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += min(n, (m - 1) / i);
    return ans;
}

int32_t main() {
    cin >> n;
    int l = 0, r = 1e18;
    while (r - l > 1) {
        int m = (l + r) / 2;
        // cout << m << ' ' << count(m) << '\n';
        if (count(m) <= n * n / 2) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
}