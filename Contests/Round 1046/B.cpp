// Codeforces Round 1046: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second
const int INF = 1e18;

int q(char dir, int val) {
    cout << "? " << dir << ' ' << val << endl;
    int d;
    cin >> d;
    return d;
}

void res(int x, int y) { cout << "! " << x << ' ' << y << endl; }

void solve() {
    int n;
    cin >> n;
    int mxd1 = -INF, mxd2 = -INF;
    while (n--) {
        int x, y;
        cin >> x >> y;
        mxd1 = max(mxd1, x - y);
        mxd2 = max(mxd2, x + y);
    }
    q('R', 1e9);
    q('R', 1e9);
    q('D', 1e9);
    int d1 = q('D', 1e9);
    q('U', 1e9);
    q('U', 1e9);
    q('U', 1e9);
    int d2 = q('U', 1e9);
    int D1 = d1 + mxd1 - 4e9, D2 = d2 + mxd2 - 4e9;
    int x = (D1 + D2) / 2, y = (D2 - D1) / 2;
    res(x, y);
}

int32_t main() {
    // cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}