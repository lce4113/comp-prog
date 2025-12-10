// Codeforces Round 1014: Problem C

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
    int o = 0, e = 0, mo = -1, me = -1, co = 0, ce = 0;
    for (auto x : a) {
        if (x % 2) {
            o += x;
            mo = max(mo, x);
            co++;
        } else {
            e += x;
            me = max(me, x);
            ce++;
        }
    }
    if (ce == 0 || co == 0) {
        cout << max(mo, me) << '\n';
        return;
    }
    cout << o + e - (co - 1) << '\n';
    // int ans = -1;
    // if (mo != -1) ans = max(ans, mo + e);
    // if (me != -1) ans = max(ans, me + o);
    // cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}