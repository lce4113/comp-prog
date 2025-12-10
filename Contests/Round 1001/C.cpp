// Codeforces Round 1001: Problem C

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

    if (n == 1) {
        cout << a[0] << '\n';
        return;
    }

    int ans = 0;
    for (auto x : a) ans += x;
    for (int i = 0; i < n - 1; i++) {
        vector<int> b;
        for (int j = 0; j < n - 1 - i; j++) {
            b.push_back(a[j + 1] - a[j]);
        }
        a = b;
        // for (auto x : a) cout << x << ' ';
        // cout << '\n';
        int sm = 0;
        for (auto x : a) sm += x;
        ans = max(ans, abs(sm));
    }

    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}