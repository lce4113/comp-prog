#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int points = 0;
    for (auto x : a) {
        if (x == 0) points++;
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}