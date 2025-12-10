#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    string b;
    cin >> b;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<pair<int, int>> zs;
    for (int i = 0; i < n; i++) {
        while (i < n && b[i] != '0') i++;
        if (i == n) break;
        int l = i;
        while (i < n && b[i] == '0') i++;
        zs.push_back({l, i - 1});
    }

    for (int i = 0; i < n; i++) {
        if (b[i] == '0') a[i] = -INF;
    }

    int mx = -INF;
    for (int i = 0; i < n;) {
        while (b[i] == '0' && i < n) i++;
        if (i == n) break;
        for (int mn = 0, sm = 0; i < n && b[i] != '0'; i++) {
            sm += a[i];
            mx = max(mx, sm - mn);
            mn = min(mn, sm);
        }
    }

    if (mx > k) {
        cout << "NO\n";
        return;
    }

    if (mx == k) {
        cout << "YES\n";
        for (auto x : a) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (auto it : zs) {
        int L = 0, R = 0;
        for (int l = it.f - 1, sm = 0; l >= 0 && b[l] != '0'; l--) {
            sm += a[l];
            L = max(L, sm);
        }
        for (int r = it.s + 1, sm = 0; r < n && b[r] != '0'; r++) {
            sm += a[r];
            R = max(R, sm);
        }
        int c = k - L - R;
        if (c + L >= 0 && c + R >= 0) {
            cout << "YES\n";
            for (int i = it.f; i <= it.s; i++) a[i] = 0;
            a[it.f] = c;
            for (auto x : a) cout << x << ' ';
            cout << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}