// Codeforces Round 1005
// Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int ans = 0;
    if (a.back() == '1') ans++;
    for (int i = 1; i < n; i++) ans += 2 * (a[i] == '0' && a[i - 1] == '1');
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}