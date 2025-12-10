// CSES Geometry: Convex Hull

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
using pt = pair<int, int>;

int cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }
int cross(pt a, pt b, pt c) {
    pt v1 = {b.x - a.x, b.y - a.y};
    pt v2 = {c.x - a.x, c.y - a.y};
    return cross(v1, v2);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pt> P(n);
    for (auto &p : P) cin >> p.x >> p.y;

    vector<pt> h(2 * P.size());
    sort(P.begin(), P.end());
    int s = 0, t = 0;
    for (int rep = 2; rep--; s = --t, reverse(P.begin(), P.end())) {
        for (auto p : P) {
            while (t - 2 >= s && cross(h[t - 2], h[t - 1], p) < 0) t--;
            h[t++] = p;
        }
    }

    cout << t << '\n';
    for (int i = 0; i < t; i++) {
        cout << h[i].x << ' ' << h[i].y << '\n';
    }
}