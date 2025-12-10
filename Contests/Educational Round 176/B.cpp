// Codeforces Educational Round 176: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    map<int, int> mp;
    for (auto x : a) mp[x]++;

    int af = a[0], ab = a.back();
    sort(a.rbegin(), a.rend());

    if (k == 1) {
        if ((a[0] == af || a[0] == ab) && mp[a[0]] == 1) {
            cout << a[1] + max(af, ab) << '\n';
        } else {
            cout << a[0] + max(af, ab) << '\n';
        }
        return;
    }

    int ans = 0;
    for (int i = 0; i < k + 1; i++) ans += a[i];
    cout << ans << '\n';

    // for (int i = 0; i < k; i++) {
    // if (a[i] == af || a[i] == ab) {
    // return;
    // }
    // }

    // cout << ans + max(af, ab) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}