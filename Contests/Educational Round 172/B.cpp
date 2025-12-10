// Codeforces Educational Round 172: Problem B

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
    for (auto x : a) mp[x]++;
    int o = 0, t = 0;
    for (auto x : mp) {
        if (x.s == 1) o++;
        if (x.s > 1) t++;
    }
    int ans = (o + 1) / 2 * 2 + t;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}