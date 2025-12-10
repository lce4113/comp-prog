// Codeforces Educational Round 177
// Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define s second
#define f first

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        x--;
    }

    vector<int> cyc(n);
    vector<int> csz(n);
    for (int i = 0; i < n; i++) {
        if (cyc[i]) continue;
        cyc[i] = i;
        int st = i, c = a[i], sz = 1;
        while (c != st) {
            // cout << c << '\n';
            cyc[c] = i;
            c = a[c], sz++;
        }
        csz[i] = sz;
    }

    // for (auto x : csz) cout << x << ' ';
    // cout << '\n';
    // for (auto x : cyc) cout << x << ' ';
    // cout << '\n';

    int ans = 0;
    for (int q = 0; q < n; q++) {
        int p;
        cin >> p;
        p--;
        ans += csz[cyc[p]];
        csz[cyc[p]] = 0;
        // cout << p << '\n';
        // for (auto x : csz) cout << x << ' ';
        // cout << '\n';
        cout << ans << ' ';
    }
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}