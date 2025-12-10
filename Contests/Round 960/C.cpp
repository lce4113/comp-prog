// Codeforces Round 960: Problem C
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
    vector<int> m;
    int mad = 0, ans = 0;
    for (auto x : a) {
        mp[x]++;
        if (mp[x] >= 2) mad = max(mad, x);
        m.push_back(mad);
        ans += x;
    }

    // for (auto x : m) cout << x << ' ';
    // cout << '\n';

    int c = 0;
    for (int i = 1; i < n; i++) {
        if (m[i] == m[i - 1]) c = m[i];
        // cout << c << ' ';
        ans += (n - i) * c + m[i];
    }
    // cout << '\n';

    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}