// CSES Geometry: Polygon Area

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
using P = pair<int, int>;

int area(vector<P> &a) {
    a.push_back(a[0]);
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += a[i].x * a[i + 1].y - a[i].y * a[i + 1].x;
    }
    a.pop_back();
    return abs(ans);
}

void solve() {
    int n;
    cin >> n;
    vector<P> a(n);
    for (auto &p : a) cin >> p.x >> p.y;
    cout << area(a) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}