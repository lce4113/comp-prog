// Codeforces Round 996: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int mn = 1e18, nm = 0, val;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            val = b[i] - a[i];
            nm++;
        } else {
            mn = min(mn, a[i] - b[i]);
        }
    }
    // cout << val << ' ' << mn << ' ' << nm << '\n';
    if (nm == 0) {
        cout << "YES\n";
        return;
    }
    if (nm >= 2) {
        cout << "NO\n";
        return;
    }
    if (mn >= val) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}