// Codeforces Round 960: Problem B
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    vector<int> a(n, -1);
    for (int i = 0; i < y; i++) a[i] = (y - i) % 2 ? -1 : 1;
    for (int i = y; i <= x; i++) a[i] = 1;
    for (int i = x + 1; i < n; i++) a[i] = (i - x) % 2 ? -1 : 1;
    for (auto x : a) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}