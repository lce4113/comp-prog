// Codeforces Round 1005
// Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    map<int, int> mp;
    for (auto x : a) mp[x]++;
    int ans = 0, ml = -1, mr = -1;
    for (int i = 0; i < n; i++) {
        int c = 0, l = i, r = i;
        while (i < n && mp[a[i]] == 1) i++, c++, r++;
        if (c > ans) ans = c, ml = l, mr = r;
    }

    if (ml == -1) {
        cout << "0\n";
        return;
    }
    cout << ml + 1 << ' ' << mr << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}