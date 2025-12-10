// CSES Sorting & Searching: Factory Machines

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
vector<int> a;

bool ch(int t) {
    int ans = 0;
    for (auto x : a) {
        ans += t / x;
        if (ans >= k) return 1;
    }
    return 0;
}

void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    for (auto &x : a) cin >> x;

    int l = 0, r = 1e18 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (ch(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}