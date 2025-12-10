// Codeforces Round 951: Problem A

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
    int ans = 1e9;
    for (int i = 1; i < n; i++) {
        ans = min(ans, max(a[i - 1], a[i]));
    }
    cout << ans - 1 << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}