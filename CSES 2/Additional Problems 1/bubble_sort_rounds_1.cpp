// CSES Additional Problems I: Bubble Sort Rounds I

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
    for (int i = 0; i < n; i++) {
        mp[a[i]].push_back(i);
    }
    int c = 0, ans = 0;
    for (auto [v, ps] : mp) {
        for (auto p : ps) ans = max(ans, p - c++);
    }
    cout << ans << '\n';
}