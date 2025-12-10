// Codeforces Round 995: Problem E

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

    vector<pair<int, int>> ln;
    for (auto x : a) ln.push_back({x, 1});
    for (auto x : b) ln.push_back({x, -1});
    sort(ln.begin(), ln.end());

    int c = n, sz = 0, ans = -1;
    for (int i = 0; i < (int)ln.size(); i++) {
        // cout << sz << ' ' << x.f << ' ' << c << '\n';
        auto x = ln[i];
        if (!(i > 0 && ln[i].f == ln[i - 1].f) && sz <= k)
            ans = max(ans, x.f * c);
        if (x.s == -1) c--;
        sz += x.s;
    }

    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}