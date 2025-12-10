// EPIC IT Round Summer 2024: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

bool ch(vector<pair<int, int>> ns, int m, int mv) {
    int c = 0;
    for (auto x : ns) {
        // cout << x.f << ' ' << x.s << ' ' << mv << '\n';
        if (-x.s <= mv) continue;
        if (c + x.f > m) return true;
        c += x.f;
        // cout << c << '\n';
    }
    return false;
}

bool ok(vector<int> a) {
    int sm = 0;
    for (auto x : a) {
        sm += x;
        if (sm < 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());

    vector<int> b(n + 1, 0), c(n + 1, 1);
    for (auto x : a) b[x]++;
    c[0] = 0;

    vector<pair<int, int>> ns;
    for (int i = 1; i <= n; i++) ns.push_back({b[i], i});
    sort(ns.begin(), ns.end());

    int ans = n;
    for (auto x : ns) {
        // cout << x.f << ' ' << x.s << '\n';
        c[x.s] = -b[x.s];
        ans--;
        // for (auto y : c) cout << y << ' ';
        // cout << '\n';
        if (!ok(c)) {
            c[x.s] = 1;
            ans++;
        }
    }
    cout << ans << '\n';

    // for (auto x : b) c.push_back(x.f);
    // sort(ns.begin(), ns.end());
    // for (auto x : ns) cout << x.f << ' ' << x.s << '\n';

    // int l = 0, r = c.size(), m = (l + r) / 2;
    // for (; r - l > 1; m = (l + r) / 2) {
    //     // cout << "m: " << m << '\n';
    //     bool v = ch(ns, m, c[m - 1]);
    //     // cout << "res: " << v << '\n';
    //     if (v)
    //         l = m;
    //     else
    //         r = m;
    //     // cout << '\n';
    // }
    // cout << r << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}