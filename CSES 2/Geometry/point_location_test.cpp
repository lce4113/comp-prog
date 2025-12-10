// CSES Geometry: Point Location Test

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
using P = pair<int, int>;

void solve() {
    P p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    P v1 = {p2.x - p1.x, p2.y - p1.y};
    P v2 = {p3.x - p1.x, p3.y - p1.y};
    int cross = v1.x * v2.y - v1.y * v2.x;
    if (cross == 0) {
        cout << "TOUCH\n";
    } else if (cross < 0) {
        cout << "RIGHT\n";
    } else {
        cout << "LEFT\n";
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}