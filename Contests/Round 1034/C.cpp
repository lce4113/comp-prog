// Codeforces Round 1034: Problem C

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
    vector<int> pref(n + 2, 1e18), suf(n + 2, -1e18);
    for (int i = 1; i <= n; i++) pref[i] = min(pref[i - 1], a[i - 1]);
    for (int i = n; i >= 1; i--) suf[i] = max(suf[i + 1], a[i - 1]);
    // for (auto x : pref) cout << x << ' ';
    // cout << '\n';
    // for (auto x : suf) cout << x << ' ';
    // cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << (pref[i] < a[i] && a[i] < suf[i + 2] ? 0 : 1);
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}