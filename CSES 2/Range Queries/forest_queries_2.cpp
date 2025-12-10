// CSES Range Queries: Forest Queries II

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) : n(_n), a(2 * _n) {}
    void u(int pos, int val) {
        for (a[pos += n] = val; pos /= 2;) {
            a[pos] = a[pos * 2] + a[pos * 2 + 1];
        }
    }
    int get(int pos) { return a[pos + n]; }
    int q(int l, int r) {
        int ans = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) ans += a[l++];
            if (r % 2) ans += a[--r];
        }
        return ans;
    }
};

struct Tree2 {
    int n;
    vector<Tree> a;
    Tree2(int _n) : n(_n), a(2 * _n, Tree(_n)) {}
    void u(int x, int y, int val) {
        for (a[x += n].u(y, val); x /= 2;) {
            a[x].u(y, a[x * 2].get(y) + a[x * 2 + 1].get(y));
        }
    }
    int q(int x1, int y1, int x2, int y2) {
        int ans = 0;
        for (x1 += n, x2 += n; x1 < x2; x1 /= 2, x2 /= 2) {
            if (x1 % 2) ans += a[x1++].q(y1, y2);
            if (x2 % 2) ans += a[--x2].q(y1, y2);
        }
        return ans;
    }
};

int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<string> a(n);
    for (auto &x : a) cin >> x;
    Tree2 seg(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '*') seg.u(i, j, 1);
        }
    }
    // for (auto x : seg.a) {
    //     for (auto y : x.a) cout << y << ' ';
    //     cout << '\n';
    // }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            a[x][y] = (a[x][y] == '*' ? '.' : '*');
            seg.u(x, y, a[x][y] == '*');
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--;
            cout << seg.q(x1, y1, x2, y2) << '\n';
        }
    }
}