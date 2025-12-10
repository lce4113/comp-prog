// Codeforces Educational Round 184: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int sm = reduce(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        a[i] = 2 * i + 2 - a[i];
    }
    int mn = 0, c = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        c += a[i];
        mn = min(mn, c);
        ans = max(ans, c - mn);
    }
    cout << ans + sm << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}