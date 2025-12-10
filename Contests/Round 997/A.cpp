// Codeforces Round 997: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.f >> x.s;
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        x += a[i].f;
        y += a[i].s;
    }
    cout << (x + m + y + m) * 2 << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}