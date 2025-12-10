// Codeforces Round 1049: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int cnt = 0;
    for (auto x : a) cnt += x == '1';
    int ans = 0;
    for (int i = n - cnt; i < n; i++) {
        ans += a[i] == '0';
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}