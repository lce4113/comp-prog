// Educational Codeforces Round 179: Problem C

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
    map<int, int> mp;
    for (int i = 0; i < n;) {
        int st = i;
        while (i < n && a[i] == a[st]) i++;
        mp[a[st]] = max(mp[a[st]], i - st);
    }
    int ans = 1e18;
    for (auto x : mp) {
        // cout << x.f << ' ' << x.s << '\n';
        ans = min(ans, x.f * (n - x.s));
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}