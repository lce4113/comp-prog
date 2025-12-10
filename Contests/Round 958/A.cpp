// Codeforces Round 958: Problem A

#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while (n > k) n -= k - 1, ans++;
    ans += (n > 1);
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}