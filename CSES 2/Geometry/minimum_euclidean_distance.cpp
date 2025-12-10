// CSES Geometry: Minimum Euclidean Distance

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
using pt = pair<int, int>;

pt swp(pt p) { return {p.y, p.x}; }
int dst(pt a, pt b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pt> P(n);
    for (auto &p : P) cin >> p.x >> p.y;
    sort(P.begin(), P.end());

    set<pt> S;
    int j = 0, dist = 2e9, ans = 8e18;
    for (auto &p : P) {
        while (P[j].x <= p.x - dist) S.erase(swp(P[j++]));
        auto lo = S.lower_bound({p.y - dist, p.x - dist});
        auto hi = S.upper_bound({p.y + dist, p.x});
        while (lo != hi) {
            ans = min(ans, dst(*lo, swp(p)));
            dist = ceil(sqrtl(ans));
            lo++;
        }
        S.insert(swp(p));
    }

    cout << ans << '\n';
}