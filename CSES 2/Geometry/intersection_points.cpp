// CSES Geometry: Intersection Points

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6;

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) : n(_n), a(2 * _n) {}
    void u(int pos, int val) {
        for (a[pos += n] += val; pos /= 2;) {
            a[pos] = a[pos * 2] + a[pos * 2 + 1];
        }
    }
    int q(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) res += a[l++];
            if (r % 2) res += a[--r];
        }
        return res;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    // rem -> x, tp = 1, y, -1
    // que -> x, tp = 2, y1, y2
    // add -> x, tp = 3, y, -1
    vector<array<int, 4>> es;
    while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            es.push_back({x1, 2, y1, y2});
        } else {
            if (x1 > x2) swap(x1, x2);
            es.push_back({x1, 3, y1, -1});
            es.push_back({x2, 1, y1, -1});
        }
    }
    sort(es.begin(), es.end());

    int ans = 0;
    Tree seg(2 * MAXN + 1);
    for (auto [_, tp, y1, y2] : es) {
        if (tp == 1) {
            seg.u(y1 + MAXN, -1);
        } else if (tp == 2) {
            ans += seg.q(y1 + 1 + MAXN, y2 + MAXN);
        } else {
            seg.u(y1 + MAXN, 1);
        }
    }
    cout << ans << '\n';
}