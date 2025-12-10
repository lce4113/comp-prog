// Codeforces Educational Round 183: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int ca = 0, cb = 0;
    for (auto x : a) ca += x == 'a';
    for (auto x : a) cb += x == 'b';
    vector<int> pfs(1, 0);
    for (int i = 0; i < n; i++) {
        pfs.push_back(pfs.back() + (a[i] == 'a') - (a[i] == 'b'));
    }
    int ans = 1e9;
    map<int, int> mp;
    for (int i = n; i >= 0; i--) {
        int c = pfs[i] + ca - cb;
        mp[pfs[i]] = i;
        if (mp.count(c)) ans = min(ans, mp[c] - i);
    }
    cout << (ans == n ? -1 : ans) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}