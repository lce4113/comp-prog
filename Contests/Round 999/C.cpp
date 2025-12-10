// Codeforces Round 999: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    map<pair<int, int>, int> c;
    c[{0, 0}] = 1;
    for (int i = 0; i < n; i++) {
        map<pair<int, int>, int> nc;
        for (auto x : c) {
            if (a[i] == x.f.f) nc[{x.f.f, 0}] += x.s, nc[{x.f.f, 0}] %= MOD;
            if (!x.f.s) nc[{x.f.f + 1, 1}] += x.s, nc[{x.f.f + 1, 1}] %= MOD;
        }
        c = nc;
        // for (auto x : c) cout << x.f.f << ' ' << x.f.s << ' ' << x.s << '\n';
        // cout << '\n';
    }

    int ans = 0;
    for (auto x : c) ans += x.s, ans %= MOD;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}