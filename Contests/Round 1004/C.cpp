// Codeforces Round 1004: Problem C

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    int ans = (a.back() - '0' + 3) % 10;
    if (n == 1) ans = min(ans, 8);
    if (n > 1) ans = min(ans, 7);
    bool zs = true;
    for (int i = n - 2; i >= 0; i--) {
        int d = (7 - (a[i] - '0') + 10) % 10;
        // cout << i << ' ' << (a[i] - '0') << ' ' << (a[n - 1] - '0') << '\n';
        if ((a[i] - '0') + (a[n - 1] - '0') < 7 && zs) d++;
        ans = min(ans, d);
        if (zs && (a[i] - '0') == 8) ans = min(ans, (a[n - 1] - '0') + 1);
        if (a[i] - '0' != 0) zs = false;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
