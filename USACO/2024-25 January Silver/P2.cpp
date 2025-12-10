// USACO 2024-25 January Silver
// Problem 2. "Farmer John's Favorite Operation"

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> am;
    for (auto x : a) am.push_back(x % m);
    sort(am.begin(), am.end());

    int c = 0;
    for (auto x : am) c += abs(am[n / 2] - x);

    // cout << c << ' ';
    int ans = c;
    for (int i = 0; i < n; i++) {
        c -= abs(am[(n / 2 + i) % n] - am[i]);
        c += abs(am[(n / 2 + i + 1) % n] - (am[i] + m));
        if (n % 2 == 0) {
            c -= abs(am[(n / 2 + i) % n] - am[(i + 1) % n]);
            c += abs(am[(n / 2 + i + 1) % n] - am[(i + 1) % n]);
        }
        am[i] += m;
        // cout << c << ' ';
        ans = min(ans, c);
    }
    // cout << '\n';

    cout << ans << '\n';
}
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
