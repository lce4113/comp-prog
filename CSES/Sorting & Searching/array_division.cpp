// CSES Sorting & Searching: Array Division

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> a;
int n, k;

bool ch(int m) {
    int c = 0, tot = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > m) return 0;
        if (c + a[i] <= m) {
            c += a[i];
        } else {
            c = a[i];
            tot++;
        }
    }
    return tot <= k;
}

void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    for (auto &x : a) cin >> x;
    int l = 0, r = 1e18;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (ch(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}