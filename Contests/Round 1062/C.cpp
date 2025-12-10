#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (auto x : a) {
        if (x % 2 != a[0] % 2) {
            sort(a.begin(), a.end());
            break;
        }
    }
    for (auto y : a) cout << y << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}