// CSES Geometry: Line Segments Trace II

#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Line {
    int a, b; // a*x+b
    int get(int x) { return a * x + b; }
};

struct LCT {
    int n;
    vector<Line> lct;
    LCT(int _n) { n = 1 << (1 + __lg(_n)), lct.assign(2 * n, {0, -1}); }
    void add(Line l, int L, int R) { add(l, L, R, 1, 0, n); }
    void add(Line l, int L, int R, int i, int lo, int hi) {
        if (L >= hi || R <= lo) return;
        if (L <= lo && hi <= R) {
            add(l, i, lo, hi);
            return;
        }
        int mid = (lo + hi) / 2;
        add(l, L, R, 2 * i, lo, mid);
        add(l, L, R, 2 * i + 1, mid, hi);
    }
    void add(Line l, int i, int lo, int hi) {
        if (i >= 2 * n) return;
        int mid = (lo + hi) / 2;
        if (l.get(mid) > lct[i].get(mid)) swap(lct[i], l);
        if (lct[i].a > l.a) {
            add(l, 2 * i, lo, mid);
        } else {
            add(l, 2 * i + 1, mid, hi);
        }
    }
    int q(int x) {
        int ans = -1;
        for (int i = x + n; i; i /= 2) {
            ans = max(ans, lct[i].get(x));
        }
        return ans;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    // x, 1, y1, y2 = rem
    // x, 0, y1, y2 = add
    LCT L(m + 1);
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int slope = (y2 - y1) / (x2 - x1);
        int c = y1 - slope * x1;
        L.add({slope, c}, x1, x2 + 1);
    }
    for (int i = 0; i <= m; i++) {
        cout << L.q(i) << ' ';
    }
    cout << '\n';
}