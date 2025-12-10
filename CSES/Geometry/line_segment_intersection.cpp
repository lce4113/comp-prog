// CSES Geometry: Line Segment Intersection

#include <bits/stdc++.h>
using namespace std;

#define int long double
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
    return cross(a, b, c) == 0 && (a.x - c.x) * (c.x - b.x) >= 0 &&
           (a.y - c.y) * (c.y - b.y) >= 0;
}

void solve() {
    P a, b, c, d;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;
    int oa = cross(c, d, a);
    int ob = cross(c, d, b);
    int oc = cross(a, b, c);
    int od = cross(a, b, d);
    if (oa * ob < 0 && oc * od < 0) {
        cout << "YES\n";
        return;
    }
    if (on(a, b, c) || on(a, b, d) || on(c, d, a) || on(c, d, b)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}