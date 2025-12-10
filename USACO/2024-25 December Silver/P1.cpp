// USACO 2024-25 December Contest, Silver
// Problem 1. "Cake Game"

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pfs(1, 0);
    for (auto x : a) pfs.push_back(pfs.back() + x);
    vector<int> rpfs(1, 0);
    reverse(a.begin(), a.end());
    for (auto x : a) rpfs.push_back(rpfs.back() + x);

    int ans = -1;
    for (int i = 0; i <= n / 2 - 1; i++) {
        int c = pfs[i] + rpfs[n / 2 - 1 - i];
        ans = max(ans, c);
    }
    cout << pfs[n] - ans << ' ' << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}