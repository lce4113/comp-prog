// Codeforces Round 951: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int a, b;
    cin >> a >> b;

    int ans = 0;
    while (a || b) {
        if (a % 2 != b % 2) break;
        a /= 2, b /= 2, ans++;
    }

    cout << (1ll << ans) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}