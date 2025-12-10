// Codeforces Round 1005
// Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> plp(1, 0), nrp(n + 1, 0);
    for (int i = 0; i < n; i++) {
        plp.push_back(plp.back() + max(0ll, a[i]));
    }
    for (int i = n - 1; i >= 0; i--) {
        nrp[i] = nrp[i + 1] + min(0ll, a[i]);
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, abs(nrp[i]) + plp[i]);
    }
    cout << ans << '\n';

    // for (auto x : plp) cout << x << ' ';
    // cout << '\n';
    // for (auto x : nrp) cout << x << ' ';
    // cout << '\n';

    // for (int i = 0; i < n;) {
    //     b.push_back(0);
    //     if (a[i] > 0) {
    //         while (i < n && a[i] > 0) b[b.size() - 1] += a[i++];
    //     } else {
    //         while (i < n && a[i] < 0) b[b.size() - 1] += a[i++];
    //     }
    // }

    // for (auto x : b) cout << x << ' ';
    // cout << '\n';

    // int N = b.size();
    // int ans = 0;
    // for (int i = 0; i < N; i++) {
    //     ans = max(ans, b[i]);
    // }
    // for (int i = 0; i < N - 1; i++) {
    //     if (b[i] > 0 && b[i + 1] < 0) ans = max(ans, abs(b[i]) + abs(b[i +
    //     1]));
    // }
    // cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}