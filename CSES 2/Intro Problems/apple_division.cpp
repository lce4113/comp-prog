// CSES Intro Problems: Apple Division

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    auto tot = reduce(a.begin(), a.end());
    int ans = 1e18;
    for (int i = 0; i < (1 << n); i++) {
        int sm = 0;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) == 0) continue;
            sm += a[j];
        }
        ans = min(ans, abs((tot - sm) - sm));
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
