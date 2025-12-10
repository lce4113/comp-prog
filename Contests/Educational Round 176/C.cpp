// Codeforces Educational Round 176: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (auto &x : a) {
        cin >> x;
        x = min(x, n - 1);
    }

    sort(a.begin(), a.end());

    vector<int> pfs(k + 1, 0);
    for (int i = k - 1; i >= 0; i--) {
        pfs[i] = pfs[i + 1] + (n - 1 - a[i]);
    }

    // for (auto x : pfs) cout << x << ' ';
    // cout << '\n';

    int ans = 0;
    for (int i = 0; i < k - 1; i++) {
        int p = lower_bound(a.begin(), a.end(), n - a[i]) - a.begin();
        p = max(p, i + 1);
        // cout << "k: " << p << ' ' << k << ' ' << i << '\n';
        ans += a[i] * (k - p) - pfs[p];
    }
    cout << 2 * ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}