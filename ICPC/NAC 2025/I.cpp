// NAC 2025: Problem I

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
using pt = pair<ld, ld>;
#define x first
#define y second

void solve() {
    int n;
    cin >> n;
    vector<pt> a(n);
    for (auto &p : a) cin >> p.x >> p.y;
    map<int, vector<int>> X, Y;
    for (int i = 0; i < n; i++) {
        ld x1 = a[i].x, x2 = a[(i + 1) % n].x, y1 = a[i].y,
           y2 = a[(i + 1) % n].y;
        if (x1 > x2) swap(x1, x2), swap(y1, y2);
        for (int cx = ceil(x1); cx <= x2; cx++) {
            // a[i].y = m*a[i].x + b
            // a[i+1].y = m*a[i+1].x + b
            ld m = (y2 - y1) / (x2 - x1);
            ld b = y1 - m * x1;
            ld cy = m * cx + b;
            X[cx].push_back(floor(cy));
        }
        if (y1 > y2) swap(x1, x2), swap(y1, y2);
        for (int cy = ceil(y1); cy <= y2; cy++) {
            // a[i].y = m*a[i].x + b
            // a[i+1].y = m*a[i+1].x + b
            ld m = (x2 - x1) / (y2 - y1);
            ld b = x1 - m * y1;
            ld cx = m * cy + b;
            Y[cy].push_back(floor(cx));
        }
    }
    vector<int> ans;
    for (auto &[_, v] : X) {
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i += 2) {
            ans.push_back(v[i]);
        }
    }
    for (auto &[_, v] : Y) {
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i += 2) {
            ans.push_back(v[i]);
        }
    }
    cout << ans.size() << '\n';
    for (auto z : ans) cout << z << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}