// Codeforces Round 1049: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.f >> x.s;

    vector<pair<int, int>> b;
    for (auto x : a) b.push_back({x.s + x.f, -x.f});
    sort(b.rbegin(), b.rend());

    int sm1 = 0, sm2 = 0;
    for (int i = 0; i < (n + 1) / 2; i++) sm1 += b[i].f;
    for (auto x : b) sm2 += x.s;

    if (n % 2 == 0) {
        int ans = sm1 + sm2;
        for (auto x : a) ans += x.s - x.f;
        cout << ans << '\n';
        return;
    }

    int ans = 0;
    // cout << sm1 << ' ' << sm2 << '\n';
    for (int i = 0; i < n / 2; i++) {
        int c = sm1 - b[i].f + sm2 - b[i].s;
        // cout << c << '\n';
        ans = max(ans, c);
    }
    sm1 -= b[n / 2].f;
    for (int i = n / 2; i < n; i++) {
        int c = sm1 + sm2 - b[i].s;
        ans = max(ans, c);
        // cout << c << '\n';
    }
    for (auto x : a) ans += x.s - x.f;
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}