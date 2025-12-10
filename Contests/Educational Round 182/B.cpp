// Codeforces Educational Round 182: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    set<int> rem;
    for (int i = 1; i <= n; i++) rem.insert(i);
    for (auto x : a) rem.erase(x);
    int i = n - 1;
    for (auto x : rem) {
        while (a[i] != 0) i--;
        a[i] = x;
    }
    int l = 0, r = n - 1;
    while (l < n && a[l] == l + 1) l++;
    while (r >= 0 && a[r] == r + 1) r--;
    int ans = r - l + 1;
    cout << (ans < 0 ? 0 : ans) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}