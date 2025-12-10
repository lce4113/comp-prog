// Codeforces Educational Round 169: Problem D

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, q;
    cin >> n >> q;
    vector<string> a(n);
    for (auto &x : a) cin >> x;

    vector<string> ps = {"BG", "BR", "BY", "GR", "GY", "RY"};
    map<string, string> op;
    // BG, BR, BY, GR, GY, RY
    op["BG"] = "RY";
    op["BR"] = "GY";
    op["BY"] = "GR";
    op["GR"] = "BY";
    op["GY"] = "BR";
    op["RY"] = "BG";

    map<string, int> mpl, mpr;
    vector<int> l(n, -1), r(n, n);
    for (int i = 0; i < n; i++) {
        for (auto x : ps) {
            if (x == a[i] || x == op[a[i]]) continue;
            if (mpl.count(x)) l[i] = max(l[i], mpl[x]);
        }
        mpl[a[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        // for (auto x : mpr) cout << x.f << ' ' << x.s << '\n';
        // cout << '\n';
        for (auto x : ps) {
            if (x == a[i] || x == op[a[i]]) continue;
            // cout << x << ' ' << i << '\n';
            if (mpr.count(x)) r[i] = min(r[i], mpr[x]);
        }
        mpr[a[i]] = i;
    }
    // for (auto x : l) cout << x << ' ';
    // cout << '\n';
    // for (auto x : r) cout << x << ' ';
    // cout << '\n';

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (a[y] != op[a[x]]) {
            cout << abs(x - y) << '\n';
            continue;
        }
        int ans = 1e9;
        if (l[x] != -1) ans = min(ans, abs(l[x] - x) + abs(l[x] - y));
        if (r[x] != n) ans = min(ans, abs(r[x] - x) + abs(r[x] - y));
        cout << (ans == 1e9 ? -1 : ans) << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}