// CSES Geometry: Robot Path

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
using pt = pair<int, int>;

struct Tree {
    int n;
    vector<int> a;
    Tree(int _n) { n = 1 << (__lg(_n) + 1), a.assign(2 * n, 0); }
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
    int walk(int L, int l = 0, int r = -1, int i = 1) {
        if (r == -1) r = n;
        if (r - l == 1) return l;
        int m = (l + r) / 2;
        if (a[2 * i] && m > L) return walk(L, l, m, 2 * i);
        return walk(L, m, r, 2 * i + 1);
    }
};

int n;
vector<pair<pt, pt>> P(1, {{0, 0}, {0, 0}});
int N = 0;
map<int, int> mp, mpr;

int dst(pt a, pt b) {
    return abs(mpr[a.x] - mpr[b.x]) + abs(mpr[a.y] - mpr[b.y]);
}
bool mid(int m, int a, int b) { return (a - m) * (m - b) >= 0; }

vector<int> overlap(pair<int, int> r1, pair<int, int> r2) {
    if (r1.x > r1.y) swap(r1.x, r1.y);
    if (r2.x > r2.y) swap(r2.x, r2.y);
    vector<int> res;
    for (int i = max(r1.x, r2.x); i <= min(r1.y, r2.y); i++) res.push_back(i);
    return res;
}

vector<pt> find_inters(pair<pt, pt> a, pair<pt, pt> b) {
    bool ah = a.x.y == a.y.y;
    bool bh = b.x.y == b.y.y;
    vector<pt> res;
    if (ah && bh && a.x.y == b.x.y) {
        vector<int> xs = overlap({a.x.x, a.y.x}, {b.x.x, b.y.x});
        for (auto cx : xs) res.push_back({cx, a.x.y});
        return res;
    }
    if (!ah && !bh && a.x.x == b.x.x) {
        vector<int> ys = overlap({a.x.y, a.y.y}, {b.x.y, b.y.y});
        for (auto cy : ys) res.push_back({a.x.x, cy});
        return res;
    }
    if (ah && !bh && mid(a.x.y, b.x.y, b.y.y) && mid(b.x.x, a.x.x, a.y.x))
        return {{b.x.x, a.x.y}};
    if (!ah && bh && mid(a.x.x, b.x.x, b.y.x) && mid(b.x.y, a.x.y, a.y.y))
        return {{a.x.x, b.x.y}};
    return {};
}

bool check(int m) {
    vector<pair<pt, pt>> C(P.begin(), P.begin() + m);
    // add -> x, tp = 1, y1, -1
    // que -> x, tp = 2, y1, y2
    // rem -> x, tp = 3, y1, -1
    vector<array<int, 4>> es;
    // y1, y2, rev, order
    map<int, vector<pair<int, int>>> mpv;
    for (auto [p1, p2] : C) {
        if (p1.x == p2.x) {
            if (p1.y > p2.y) swap(p1, p2);
            es.push_back({p1.x, 2, p1.y, p2.y});
            mpv[p1.x].push_back({p1.y, p2.y});
        } else {
            if (p1.x > p2.x) swap(p1, p2);
            es.push_back({p1.x, 1, p1.y, -1});
            es.push_back({p2.x, 3, p1.y, -1});
        }
    }
    sort(es.begin(), es.end());
    Tree seg(N);
    for (auto &[cx, tp, y1, y2] : es) {
        if (tp == 1) {
            if (seg.q(y1, y1 + 1)) return 0;
            seg.u(y1, 1);
        } else if (tp == 2) {
            if (seg.q(y1, y2 + 1) != 0) return 0;
        } else {
            seg.u(y1, -1);
        }
    }
    for (auto &[cx, ys] : mpv) {
        sort(ys.begin(), ys.end());
        int l = ys.size();
        for (int i = 1; i < l; i++) {
            if (ys[i - 1].y >= ys[i].x) return 0;
        }
    }
    return 1;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    pt c = {0, 0};
    vector<int> pfs(1, 0);
    char lst = '.';
    for (int i = 0; i < n; i++) {
        char dir;
        int dst;
        cin >> dir >> dst;
        pfs.push_back(pfs.back() + dst);
        P.push_back({c, c});
        if (dir == 'R') {
            if (lst != 'L') P.back().x.x++;
            c.x += dst;
        }
        if (dir == 'L') {
            if (lst != 'R') P.back().x.x--;
            c.x -= dst;
        }
        if (dir == 'U') {
            if (lst != 'D') P.back().x.y++;
            c.y += dst;
        }
        if (dir == 'D') {
            if (lst != 'U') P.back().x.y--;
            c.y -= dst;
        }
        P.back().y = c;
        lst = dir;
    }
    for (auto [p1, p2] : P) mp[p1.x], mp[p1.y], mp[p2.x], mp[p2.y];
    for (auto &[v, cmp] : mp) mpr[N] = v, cmp = N++;
    for (auto &[p1, p2] : P)
        p1.x = mp[p1.x], p1.y = mp[p1.y], p2.x = mp[p2.x], p2.y = mp[p2.y];

    int l = 2, r = n + 2;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    if (l == n + 1) {
        cout << pfs.back() << '\n';
        return 0;
    }
    int last = 1e18;
    for (int i = 0; i < l; i++) {
        auto ps = find_inters(P[i], P[l]);
        for (auto p : ps) {
            last = min(last, dst(p, P[l - 1].y));
        }
    }
    cout << pfs[l - 1] + last << '\n';
}