// CSES Sorting & Searching: Restaurant Customers

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, 1});
        a.push_back({y, -1});
    }
    sort(a.begin(), a.end());
    int c = 0, ans = -1;
    for (auto x : a) {
        c += x.s;
        ans = max(ans, c);
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}