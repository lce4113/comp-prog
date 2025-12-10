#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> mp(m);
    for (int i = 0; i < m; i++) mp[i] = i;
    for (int i = 0; i < m; i++) {
        int a, d, k;
        cin >> a >> d >> k;
        for (int x = a + d; x <= a + d * k; x += d) {
            // cout << x << ' ' << a << '\n';
            mp[x - 1] = mp[a - 1];
        }
    }
    set<int> ans;
    for (auto x : mp) {
        ans.insert(x);
    }
    cout << ans.size() << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}