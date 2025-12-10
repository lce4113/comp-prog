// Codeforces Round 992: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    int ans = 1, c = 1;
    while (c < n) {
        c++, ans++;
        // cout << c << '\n';
        if (c >= n) break;
        c *= 2;
        // cout << c << '\n';
    }
    cout << ans << '\n';
    // cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}