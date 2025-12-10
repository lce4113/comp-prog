// EPIC IT Round Summer 2024: Problem B

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
    int cm = 0, ans = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        cm = max(cm, a[i]);
        ans += cm - a[i];
        mx = max(mx, cm - a[i]);
    }
    ans += mx;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}