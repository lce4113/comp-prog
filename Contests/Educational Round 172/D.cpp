// Codeforces Educational Round 172: Problem D

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second
typedef pair<int, int> pi;

void solve() {
    int n;
    cin >> n;
    vector<pair<pi, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].f.f >> a[i].f.s;
        a[i].s = i;
    }
    sort(a.begin(), a.end(), [](pair<pi, int> x, pair<pi, int> y) {
        return (x.f.f == y.f.f ? x.f.s > y.f.s : x.f.f < y.f.f);
    });
    // for (auto x : a) cout << x.f.f << ' ' << x.f.s << ' ' << x.s << '\n';
    vector<int> ans(n, 0);

    set<int> rs;
    for (int i = 0; i < n; i++) {
        auto lb = rs.lower_bound(a[i].f.s);
        if (lb != rs.end()) {
            int r = *lb - a[i].f.s;
            ans[a[i].s] += r;
        }
        rs.insert(a[i].f.s);
    }

    sort(a.begin(), a.end(), [](pair<pi, int> x, pair<pi, int> y) {
        return (x.f.s == y.f.s ? x.f.f < y.f.f : x.f.s > y.f.s);
    });
    // for (auto x : a) cout << x.f.f << ' ' << x.f.s << ' ' << x.s << '\n';

    set<int> ls;
    for (int i = 0; i < n; i++) {
        auto ub = ls.upper_bound(a[i].f.f);
        if (ub != ls.begin()) {
            ub--;
            int l = a[i].f.f - *ub;
            ans[a[i].s] += l;
        }
        ls.insert(a[i].f.f);
    }

    for (int i = 1; i < n; i++) {
        if (a[i].f.f == a[i - 1].f.f && a[i].f.s == a[i - 1].f.s) {
            ans[a[i].s] = 0;
            ans[a[i - 1].s] = 0;
        }
    }

    for (auto x : ans) cout << x << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}