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
    vector<int> d;
    for (int i = 1; i < n; i++) d.push_back(a[i] - a[i - 1]);

    if (n == 1) {
        cout << 1 << '\n';
    } else if (n % 2 == 0) {
        int mx = 1;
        for (int i = 1; i < n; i += 2) {
            mx = max(mx, a[i] - a[i - 1]);
        }
        cout << mx << '\n';
        return;
    } else {
        int ans = LLONG_MAX;
        vector<int> pos;
        for (int i = 1; i < n - 1; i += 2) pos.push_back(i);
        for (int i = 0; i < (int)pos.size(); i++) {
            int mx = LLONG_MIN;
            for (auto x : pos) {
                mx = max(a[x + 1] - a[x], mx);
            }
            ans = min(ans, mx);
            pos[i]--;
        }
        int mx = LLONG_MIN;
        for (auto x : pos) {
            mx = max(a[x + 1] - a[x], mx);
        }
        ans = min(ans, mx);
        cout << ans << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}