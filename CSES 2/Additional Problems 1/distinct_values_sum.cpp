// CSES Additional Problems I: Distinct Values Sum

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) mp[a[i]].push_back(i);
    int ans = 0;
    for (int i = 0; i < n; i++) ans += (i + 1) * (n - i);
    for (auto [v, ps] : mp) {
        int m = ps.size();
        for (int i = 1; i < m; i++) {
            ans -= (ps[i - 1] + 1) * (n - ps[i]);
        }
    }
    cout << ans << '\n';
}