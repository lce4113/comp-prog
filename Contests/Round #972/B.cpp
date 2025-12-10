#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(m);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    while (q--) {
        int pos;
        cin >> pos;
        int x = lower_bound(a.begin(), a.end(), pos) - a.begin();
        if (x == m) {
            cout << (n - a.back()) << '\n';
            continue;
        }
        if (x == 0) {
            cout << (a[0] - 1) << '\n';
            continue;
        }
        cout << (a[x] - a[x - 1]) / 2 << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}