// Codeforces Round 998: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    map<int, int> mp;
    mp[a1 + a2]++;
    mp[a3 - a2]++;
    mp[a4 - a3]++;
    int mxi = a1 + a2;
    for (auto x : mp)
        if (x.s > mp[mxi]) mxi = x.f;
    cout << mp[mxi] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}