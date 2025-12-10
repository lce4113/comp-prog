#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.first >> x.second;
    int minw = INT_MIN, minh = INT_MIN;
    for (auto x : a) {
        minw = max(x.first, minw);
        minh = max(x.second, minh);
    }
    cout << (2 * minw + 2 * minh) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}