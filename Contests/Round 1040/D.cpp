// Codeforces Round 1040: Problem D

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
    vector<int> ps(n);
    for (int i = 0; i < n; i++) ps[a[i] - 1] = i;
    int ans = 0;
    for (auto i : ps) {
        int i1 = 0, i2 = 0;
        for (int j = 0; j < i; j++) {
            i1 += a[i] < a[j];
            i2 += (2 * n - a[i]) < a[j];
        }
        for (int j = i + 1; j < n; j++) {
            i1 += a[i] > a[j];
            i2 += (2 * n - a[i]) > a[j];
        }
        if (i2 < i1) {
            a[i] = 2 * n - a[i];
            ans += i2;
        } else {
            ans += i1;
        }
    }
    cout << ans / 2 << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}