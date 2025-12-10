// Columbia Programming Camp
// Spring 2025 Contest #1
// Problem K

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
    vector<pair<int, int>> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = {a[i], b[i]};
    }
    sort(c.rbegin(), c.rend());

    int C = 0, ans = c[0].f;
    for (int i = 0; i < n - 1; i++) {
        C += c[i].s;
        ans = min(ans, max(C, c[i + 1].f));
    }
    C += c.back().s;
    ans = min(ans, C);
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}