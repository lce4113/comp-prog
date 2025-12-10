// CSES Sorting & Searching: Reading Books

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    auto tot = reduce(a.begin(), a.end());
    auto mx = *max_element(a.begin(), a.end());
    cout << max(tot, mx * 2) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}