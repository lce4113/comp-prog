// Codeforces Round 1045: Problem C

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
    int ans = 0;
    if (a[0] > a[1]) {
        ans += a[0] - a[1];
        a[0] = a[1];
    }
    for (int i = 1; i + 1 < n; i += 2) {
        if (a[i + 1] + a[i - 1] - a[i] < 0) continue;
        ans += a[i + 1] + a[i - 1] - a[i];
        if (a[i + 1] < a[i + 1] + a[i - 1] - a[i]) {
            a[i + 1] = 0;
            a[i - 1] = a[i];
        } else {
            a[i + 1] -= a[i + 1] + a[i - 1] - a[i];
        }
    }
    if (n % 2 == 0 && a[n - 2] > a[n - 1]) {
        ans += a[n - 2] - a[n - 1];
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}