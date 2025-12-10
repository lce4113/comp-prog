// CSES Mathematics: Another Game

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    string ans = "second\n";
    for (auto x : a)
        if (x % 2) ans = "first\n";

    cout << ans;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}