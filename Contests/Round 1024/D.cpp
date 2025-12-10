// Codeforces Round 1024: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Tree {
    typedef int T;
    static constexpr T unit = 0;
    T f(T x, T y) { return x + y; }
    vector<T> a;
    int n;
    Tree(int n) : a(2 * n, unit), n(n) {}
    void u(int pos, T val) {
        for (a[pos += n] = val; pos /= 2;)
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
    }
    T q(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, a[b++]);
            if (e % 2) rb = f(a[--e], rb);
        }
        return f(ra, rb);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), o, e;
    for (auto &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        if (i % 2) o.push_back(a[i]);
        if (i % 2 == 0) e.push_back(a[i]);
    }

    Tree seg1(n), seg2(n);
    vector<pair<int, int>> ap;
    for (int i = 0; i < n; i++) ap.push_back({a[i], i});
    sort(ap.begin(), ap.end());
    int inv = 0;
    for (int i = 0; i < n; i++) {
        if (ap[i].s % 2) {
            inv += seg1.q(ap[i].s, n);
            seg1.u(ap[i].s, 1);
        } else {
            inv -= seg2.q(ap[i].s, n);
            seg2.u(ap[i].s, 1);
        }
    }
    inv = (inv % 2 + 2) % 2;

    sort(o.begin(), o.end());
    sort(e.begin(), e.end());
    vector<int> ans(n);
    for (int i = 0, oi = 0, ei = 0; i < n; i++) {
        if (i % 2) ans[i] = o[oi++];
        if (i % 2 == 0) ans[i] = e[ei++];
    }
    if (inv) swap(ans[n - 1], ans[n - 3]);
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}