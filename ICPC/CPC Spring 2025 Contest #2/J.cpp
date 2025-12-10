// Spring 2025 Columbia University Local Contest
// Problem J

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

// const int MOD = 998244353;

void solve() {
    int n, A, b;
    cin >> n >> A >> b;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int p = max(0ll, n - (A / b) - 1);
    // cout << p << '\n';
    int ans = a[p] * A;
    for (int i = p + 1; i < n; i++) {
        ans += (a[i] - a[p]) * b;
    }
    cout << ans << ' ' << a[p] << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}