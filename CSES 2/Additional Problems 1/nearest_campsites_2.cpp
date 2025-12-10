// CSES Additional Problems I: Nearest Campsites II

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 1;

struct MnTree {
    static constexpr int unit = 1e18;
    int n;
    vector<int> a;
    int f(int x, int y) { return min(x, y); }
    MnTree(int _n) : n(_n), a(2 * _n, unit) {}
    void u(int pos, int val) {
        for (pos += n, a[pos] = f(a[pos], val); pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int res = unit;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) res = f(res, a[l++]);
            if (r % 2) res = f(res, a[--r]);
        }
        return res;
    }
};

struct MxTree {
    static constexpr int unit = -1e18;
    int n;
    vector<int> a;
    int f(int x, int y) { return max(x, y); }
    MxTree(int _n) : n(_n), a(2 * _n, unit) {}
    void u(int pos, int val) {
        for (pos += n, a[pos] = f(a[pos], val); pos /= 2;) {
            a[pos] = f(a[pos * 2], a[pos * 2 + 1]);
        }
    }
    int q(int l, int r) {
        int res = unit;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) res = f(res, a[l++]);
            if (r % 2) res = f(res, a[--r]);
        }
        return res;
    }
};

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> es(n + m);
    for (int i = 0; i < n; i++) {
        cin >> es[i][0] >> es[i][1];
        es[i][2] = i;
    }
    for (int i = n; i < n + m; i++) {
        cin >> es[i][0] >> es[i][1];
        es[i][2] = i;
    }
    sort(es.begin(), es.end());
    MxTree seg1(N), seg2(N);
    MnTree seg3(N), seg4(N);
    vector<int> ans(m, 1e18);
    for (auto [x, y, p] : es) {
        if (p < n) {
            seg1.u(y, x + y);
            seg2.u(y, x - y);
        } else {
            p -= n;
            ans[p] = min(ans[p], x + y - seg1.q(0, y + 1));
            ans[p] = min(ans[p], x - y - seg2.q(y, N));
        }
    }
    sort(es.rbegin(), es.rend());
    for (auto [x, y, p] : es) {
        if (p < n) {
            seg3.u(y, x + y);
            seg4.u(y, x - y);
        } else {
            p -= n;
            ans[p] = min(ans[p], seg3.q(y, N) - (x + y));
            ans[p] = min(ans[p], seg4.q(0, y + 1) - (x - y));
        }
    }
    for (auto x : ans) cout << x << ' ';
    cout << "\n";
}