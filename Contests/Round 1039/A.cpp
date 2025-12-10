// Codeforces Round 1039: Problem A

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
    if (upper_bound(a.begin(), a.end(), k) == a.begin()) {
        cout << n << '\n';
        return;
    }
    int p = --upper_bound(a.begin(), a.end(), k) - a.begin();
    int ans = n, c = 0;
    for (int i = p; i >= 0; i--) {
        while (i >= 0 && a[i] * (1ll << c) > k) i--;
        if (i < 0) break;
        ans--, c++;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}