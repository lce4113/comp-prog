// Codeforces Round 1041: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    vector<pair<int, int>> c(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        c[i] = {a[i], b[i]};
        ans += abs(a[i] - b[i]);
    }
    sort(c.begin(), c.end());
    int res = 1e9;
    for (int i = 0; i < n - 1; i++) {
        res = min(res, c[i + 1].f - c[i].s);
    }
    cout << ans + 2 * max(0ll, res) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}