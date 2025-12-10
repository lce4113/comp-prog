// Codeforces Round 1067: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    n = 2 * n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> mp;
    for (auto x : a) mp[x]++;
    int ans = 0;
    int co = 0, c4 = 0;
    for (auto x : mp) {
        if (x.s % 4 == 2)
            ans += 2;
        else if (x.s % 2) {
            co++;
        } else if (x.s % 4 == 0) {
            c4++;
        }
    }
    if (co > 0) {
        cout << ans + c4 * 2 + co << '\n';
    } else {
        cout << ans + c4 / 2 * 2 * 2 << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}