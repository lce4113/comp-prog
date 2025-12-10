#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    a.insert(a.begin(), 0);
    int ans = 0, buttons = n;
    // for (auto x : a) cout << x << ' ';
    // cout << '\n';
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) continue;
        ans += buttons;
        buttons = n - i;
        k -= n - i;
        if (k <= 0) {
            ans += k;
            break;
        }
        if (a[i] + 1 == a[i + 1]) continue;
        ans += buttons * (a[i + 1] - a[i] - 1);
        k -= (n - i) * (a[i + 1] - a[i] - 1);
        if (k <= 0) {
            ans += k;
            break;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}