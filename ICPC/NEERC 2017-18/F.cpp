// NEERC 2017-18: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
using pt = pair<int, int>;

// first quadrant, a > b
vector<pair<pt, pt>> get(int a, int b, int n) {
    vector<pair<pt, pt>> res;
    if (a <= n - 1 && b <= n - 1) {
        res.push_back({{0, -(n - b - 1)}, {n - 1, b}});
        return res;
    }
    int cx = 0, cy = 0;
    bool R = 1;
    while (abs(cy - b) + 1 > n && abs(cx - a) + 1 > n) {
        res.push_back({{cx, cy}, {cx + n - 1, cy + n - 1}});
        cx += n - 1, cy += n - 1;
        if (abs(cx - a) >= abs(cy - b))
            cx++, R = 1;
        else
            cy++, R = 0;
    }
    while (abs(cx - a) + 1 > n) {
        if (!R) R = 1, cx++, cy--;
        res.push_back({{cx, cy - n + 1}, {cx + n - 1, cy}});
        cx += n;
    }
    if (R) {
        if (a - cx == n - 1 && b - cy == n) {
            res.push_back({{cx, cy}, {cx + n - 1, cy + n - 1}});
            cx += n - 1, cy += n;
            res.push_back({{cx, cy}, {cx + n - 1, cy + n - 1}});
            return res;
        }
        res.push_back({{cx, -(n - b - 1)}, {cx + n - 1, b}});
    } else {
        if (a - cx == n && b - cy == n - 1) {
            res.push_back({{cx, cy}, {cx + n - 1, cy + n - 1}});
            cx += n, cy += n - 1;
            res.push_back({{cx, cy}, {cx + n - 1, cy + n - 1}});
            return res;
        }
        res.push_back({{a, cy + n - 1}, {a - n + 1, cy}});
    }
    return res;
}

vector<pair<pt, pt>> get1(int a, int b, int n) {
    if (a >= b) {
        return get(a, b, n);
    }
    auto res = get(b, a, n);
    for (auto &x : res) swap(x.f.f, x.f.s), swap(x.s.f, x.s.s), swap(x.f, x.s);
    return res;
}

void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    bool aneg = a < 0, bneg = b < 0;
    a = abs(a), b = abs(b);
    auto ans = get1(a, b, n);
    for (auto &x : ans) {
        x.f.f *= aneg ? -1 : 1;
        x.f.s *= bneg ? -1 : 1;
        x.s.f *= aneg ? -1 : 1;
        x.s.s *= bneg ? -1 : 1;
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x.f.f << ' ' << x.f.s << ' ' << x.s.f << ' ' << x.s.s << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}