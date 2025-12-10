// Codeforces Educational Round 184: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
const int INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (auto &x : a) cin >> x[0];
    for (auto &x : a) cin >> x[1];
    for (auto &x : a) cin >> x[2];

    // 1 point
    int ans = -INF;
    for (int i = 0; i < n; i++) {
        ans = max(ans, -a[i][2]);
    }

    // 2 points
    int maxsm = -INF, minsm = INF;
    int maxdf = -INF, mindf = INF;
    for (int i = 0; i < n; i++) {
        maxsm = max(maxsm, 2 * a[i][0] + 2 * a[i][1] - a[i][2]);
        minsm = min(minsm, 2 * a[i][0] + 2 * a[i][1] + a[i][2]);
        maxdf = max(maxdf, 2 * a[i][0] - 2 * a[i][1] - a[i][2]);
        mindf = min(mindf, 2 * a[i][0] - 2 * a[i][1] + a[i][2]);
    }
    ans = max(ans, maxsm - minsm);
    ans = max(ans, maxdf - mindf);

    // 4 points
    int maxx = -INF, minx = INF;
    int maxy = -INF, miny = INF;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx, 2 * a[i][0] - a[i][2]);
        minx = min(minx, 2 * a[i][0] + a[i][2]);
        maxy = max(maxy, 2 * a[i][1] - a[i][2]);
        miny = min(miny, 2 * a[i][1] + a[i][2]);
    }
    // cout << maxx << ' ' << minx << ' ' << maxy << ' ' << miny << '\n';
    ans = max(ans, maxx - minx + maxy - miny);

    // 3 points
    maxx = -INF, minx = INF;
    maxy = -INF, miny = INF;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        ans = max(ans, 2 * a[i][0] - minx + maxy - 2 * a[i][1] - a[i][2]);
        ans = max(ans, 2 * a[i][0] - minx + 2 * a[i][1] - miny - a[i][2]);
        maxx = max(maxx, 2 * a[i][0] - a[i][2]);
        minx = min(minx, 2 * a[i][0] + a[i][2]);
        maxy = max(maxy, 2 * a[i][1] - a[i][2]);
        miny = min(miny, 2 * a[i][1] + a[i][2]);
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        ans = max(ans, maxx - 2 * a[i][0] + maxy - 2 * a[i][1] - a[i][2]);
        ans = max(ans, maxx - 2 * a[i][0] + 2 * a[i][1] - miny - a[i][2]);
        maxx = max(maxx, 2 * a[i][0] - a[i][2]);
        minx = min(minx, 2 * a[i][0] + a[i][2]);
        maxy = max(maxy, 2 * a[i][1] - a[i][2]);
        miny = min(miny, 2 * a[i][1] + a[i][2]);
    }

    for (auto x : a) ans += x[2];
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}