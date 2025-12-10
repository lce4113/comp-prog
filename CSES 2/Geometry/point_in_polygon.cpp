// CSES Geometry: Point in Polygon

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
using P = pair<int, int>;

int cross(P a, P b) { return a.x * b.y - a.y * b.x; }
int cross(P a, P b, P c) {
    P v1 = {b.x - a.x, b.y - a.y};
    P v2 = {c.x - a.x, c.y - a.y};
    return cross(v1, v2);
}

bool on(P a, P b, P c) {
    if (cross(c, b, a) != 0) return 0;
    if ((a.x - c.x) * (b.x - c.x) > 0) return 0;
    if ((a.y - c.y) * (b.y - c.y) > 0) return 0;
    return 1;
}

int in(vector<P> &ps, P p) {
    bool ans = 0;
    int n = ps.size();
    for (int i = 0; i < n - 1; i++) {
        if (on(ps[i], ps[i + 1], p)) return 0;
        int wind = (ps[i].y > p.y) - (ps[i + 1].y > p.y);
        int side = cross(p, ps[i], ps[i + 1]) > 0 ? 1 : -1;
        ans ^= wind * side > 0;
    }
    return ans ? 1 : -1;
}

int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<P> A(n);
    for (auto &c : A) cin >> c.x >> c.y;
    A.push_back(A[0]);
    while (q--) {
        P p;
        cin >> p.x >> p.y;
        auto c = in(A, p);
        if (c == 0) {
            cout << "BOUNDARY\n";
        } else if (c > 0) {
            cout << "INSIDE\n";
        } else {
            cout << "OUTSIDE\n";
        }
    }
}