// CSES Sorting & Searching: Movie Festival

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.s >> x.f;
    sort(a.begin(), a.end());
    int ans = 0, c = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].s >= c) {
            c = a[i].f;
            ans++;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}