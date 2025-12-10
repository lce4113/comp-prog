// Codeforces Round 1049: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (n == 1) {
        cout << a[0] << '\n';
        return;
    }

    for (int i = 1; i < n; i += 2) {
        a[i] *= -1;
    }
    int ans = reduce(a.begin(), a.end());
    for (int i = 1; i < n; i += 2) {
        a[i] *= -1;
    }

    int mne = 1e18, mxo = -1e18;
    for (int i = 0; i < n; i += 2) {
        mne = min(mne, 2 * a[i] + i);
    }
    for (int i = 1; i < n; i += 2) {
        mxo = max(mxo, 2 * a[i] + i);
    }
    // cout << '\n';
    // cout << ans << ' ' << mxo << ' ' << mne << '\n';
    // for (auto x : a) cout << x << ' ';
    // cout << '\n';
    int dif = max((n - 1) / 2 * 2, mxo - mne);

    mne = 1e18, mxo = -1e18;
    for (int i = 0; i < n; i += 2) {
        mne = min(mne, 2 * a[i] - i);
    }
    for (int i = 1; i < n; i += 2) {
        mxo = max(mxo, 2 * a[i] - i);
    }
    dif = max(dif, mxo - mne);

    cout << ans + dif << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}