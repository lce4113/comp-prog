// NWERC 2024: Problem J

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
using P = pair<int, int>;

int dst(P a, P b) {
    int dx = (a.x - b.x), dy = (a.y - b.y);
    return ceil(sqrt(dx * dx + dy * dy)) - 1;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pair<int, P>> a(n);
    for (auto &b : a) {
        cin >> b.y.x >> b.y.y >> b.x;
    }

    for (int i = 0; i < n; i++) {
        int ans = a[i].x;
        for (int j = 0; j < n; j++) {
            if (a[i].x >= a[j].x) continue;
            ans = min(ans, dst(a[i].y, a[j].y));
        }
        cout << ans << '\n';
    }
}