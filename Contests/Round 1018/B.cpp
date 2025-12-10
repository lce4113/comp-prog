// Codeforces Round 1018: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    // vector<pair<int, int>> c(n);
    int ans = 1;
    for (auto &x : a) {
        cin >> x;
        ans += x;
    }
    for (auto &x : b) {
        cin >> x;
        ans += x;
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) c[i] = min(a[i], b[i]);
    sort(c.begin(), c.end());
    for (int i = 0; i < n - k + 1; i++) {
        ans -= c[i];
    }
    // for (int i = 0; i < n; i++) c[i] = {a[i] + b[i], a[i]};
    // sort(c.rbegin(), c.rend());
    // int ans = 1;
    // for (int i = 0; i < k - 1; i++) ans += c[i].f;
    // for (int j = k - 1; j < n; j++) {
    //     ans += max(c[j].f - c[j].s, c[j].s);
    // }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
