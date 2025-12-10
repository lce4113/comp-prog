// ICPC 2022 Pacific Northwest Regionals
// Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

#define db long double

struct Tree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T a, T b) { return a + b; }
    vector<T> s;
    int n;
    Tree(int n = 0, T def = unit) : s(2 * n, def), n(n) {}
    void u(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T q(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int n, x0;
    cin >> n >> x0;
    vector<array<db, 3>> a(n);
    vector<array<db, 4>> b;
    for (auto &x : a) cin >> x[0] >> x[1] >> x[2];
    for (int i = 0; i < n; i++)
        b.push_back({atan2(a[i][1], a[i][0]), atan2(a[i][1], x0 - a[i][0]),
                     a[i][2], (db)i});
    sort(b.begin(), b.end());

    // for (auto x : b) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }

    vector<db> ys;
    for (auto x : b) ys.push_back(x[1]);
    sort(ys.begin(), ys.end());
    map<db, int> mp;
    for (int i = 0; i < n; i++) {
        if (i == 0 || ys[i] != ys[i - 1]) mp[ys[i]] = i;
    }

    // for (auto x : mp) cout << x.f << ' ' << x.s << '\n';

    Tree seg(n);
    vector<int> ans(n);
    for (auto x : b) {
        int c = mp[x[1]];
        ans[x[3]] = seg.q(0, c + 1);
        // cout << "q: " << c + 1 << ' ' << seg.q(0, c + 1) << '\n';
        // cout << "u: " << c << ' ' << seg.q(c, c + 1) + x[2] << '\n';
        seg.u(c, seg.q(c, c + 1) + x[2]);
    }
    for (auto x : ans) cout << x << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}