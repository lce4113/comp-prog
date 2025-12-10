#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int k = i + 1; k < n; k++) {
            if (a[k] > a[i]) count++;
        }
        ans = min(ans, i + count);
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}