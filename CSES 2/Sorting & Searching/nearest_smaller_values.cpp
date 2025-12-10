// CSES: Nearest Smaller Values

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        while (b.size() && a[b.back()] >= a[i]) b.pop_back();
        // cout << a[i] << ", ";
        // for (auto x : b) cout << x << ' ';
        // cout << '\n';
        if (b.empty()) {
            cout << "0 ";
        } else {
            cout << b.back() + 1 << ' ';
        }
        b.push_back(i);
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}