// Codeforces Round 990: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int mxi = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] + b[i] - max(a[i], b[i]) >
            a[mxi] + b[mxi] - max(a[mxi], b[mxi]))
            mxi = i;
    }
    int ans = a[mxi] + b[mxi];
    for (int i = 0; i < n; i++) {
        if (i == mxi) continue;
        ans += max(a[i], b[i]);
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}