#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            cout << i + 1 << '\n';
            return;
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    solve();
}