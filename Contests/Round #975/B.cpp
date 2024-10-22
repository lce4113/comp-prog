#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    map<int, int> mp;
    for (int i = 1; i < n; i++) {
        int num = i * (n - i);
        mp[num] += a[i] - a[i - 1] - 1;
        mp[num + i - 1]++;
    }
    mp[n - 1]++;
    while (q--) {
        int k;
        cin >> k;
        cout << mp[k] << ' ';
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}