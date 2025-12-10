// CSES Sorting & Searching: Collecting Numbers

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) p[a[i] - 1] = i;

    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
        if (p[i] > p[i + 1]) ans++;
    }

    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}