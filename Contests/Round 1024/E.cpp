// Codeforces Round 1024: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Tree {
    typedef int T;
    static constexpr T unit = -1;
    T f(T x, T y) { return max(x, y); }
    vector<T> a;
    int n;
    Tree(int _n) {
        n = 1 << ((int)log2(_n) + 1);
        a.assign(2 * n, unit);
    }
    void u(int pos, T val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    T q(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, a[b++]);
            if (e % 2) rb = f(rb, a[--e]);
        }
        return f(ra, rb);
    }
    int kth(T k, int i = 1) {
        if (a[i] < k) return -1;
        if (i >= n) return i - n;
        if (a[i * 2] >= k) return kth(k, i * 2);
        return kth(k, i * 2 + 1);
    }
};

int n;
vector<int> a;

int ch(int m) {
    Tree seg(n), segr(n);
    for (int i = 0; i < n; i++) seg.u(i, a[i]), segr.u(n - i - 1, a[i]);
    // for (auto x : seg.a) cout << x << ' ';
    // cout << '\n';
    int ans = 0;
    for (int i = m; i >= 1; i--) {
        int lo = seg.kth(i), hi = segr.kth(i);
        if (lo == -1 || hi == -1) return -1;
        seg.u(lo, -1), seg.u(n - 1 - hi, -1);
        segr.u(n - 1 - lo, -1), segr.u(hi, -1);
        hi = n - hi - 1;
        if (lo == hi) return -1;
        ans += hi - lo;
        // cout << lo << ' ' << hi << '\n';
        // for (auto x : seg.a) cout << x << ' ';
        // cout << '\n';
    }
    return ans;
}

void solve() {
    cin >> n;
    a.assign(n, 0);
    for (auto &x : a) cin >> x;
    int l = 1, r = n + 1, m = (l + r) / 2;
    for (; r - l > 1; m = (l + r) / 2) {
        if (ch(m) == -1) {
            r = m;
        } else {
            l = m;
        }
    }
    l = -1;
    int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    for (; r - l > 2; m1 = l + (r - l) / 3, m2 = r - (r - l) / 3) {
        int x = ch(m1), y = ch(m2);
        // cout << m1 << ' ' << m2 << ' ' << x << ' ' << y << '\n';
        if (x < y) {
            l = m1;
        } else {
            r = m2;
        }
    }
    cout << ch(l + 1) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}