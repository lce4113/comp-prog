// BAPC 2025: Problem B

#include <bits/stdc++.h>
using namespace std;

using pt = pair<int, int>;
#define x first
#define y second
const long double PI = acos(-1);

long double ang(pt a, pt b) { return atan2(b.y - a.y, abs(a.x - b.x)); }

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pt> a(n);
    for (auto &p : a) cin >> p.x >> p.y;

    long double ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, ang(a[0], a[i]));
        ans = max(ans, ang(a[n - 1], a[i]));
    }
    // asdf
    cout << ans * 180.0 / PI << '\n';
}