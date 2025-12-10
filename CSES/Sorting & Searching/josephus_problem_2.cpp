// CSES Sorting & Searching: Josephus Problem II

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Tree {
    int f(int x, int y) { return x + y; }
    vector<int> a;
    int n;
    Tree(int _n) {
        n = (1ll << (1 + (int)log2(_n)));
        a.assign(2 * n, 0);
    }
    void u(int pos, int val = 0) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int ra = 0, rb = 0;
        for (l += n, r += n; r > l; l /= 2, r /= 2) {
            if (l % 2) ra = f(ra, a[l++]);
            if (r % 2) rb = f(a[--r], rb);
        }
        return f(ra, rb);
    }
    int walk(int k, int i = 1) {
        // cout << "walk: " << k << ' ' << i << ' ' << a[2 * i] << ' '
        //      << a[2 * i + 1] << '\n';
        if (i >= n) return i - n;
        if (k > a[2 * i]) return walk(k - a[2 * i], 2 * i + 1);
        return walk(k, 2 * i);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    Tree seg(2 * n);
    for (int i = 0; i < 2 * n; i++) seg.u(i, 1);
    for (int c = -1, tot = n; tot;) {
        c = seg.walk((seg.q(0, c + 1) + k + 1 - 1) % tot + 1);
        if (c >= n) c -= n;
        seg.u(c);
        seg.u(c + n);
        cout << c + 1 << ' ';
        tot--;
    }
    cout << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}