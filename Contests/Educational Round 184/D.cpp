// Codeforces Educational Round 184: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    if (y == 1) {
        cout << "-1\n";
        return;
    }
    int c = k;
    for (int r = x; r > 0;) {
        if (c - 1 < y - 1) break;
        int dst = (y - 1) - (c - 1) % (y - 1);
        int step = min(r, (dst - 1) / ((c - 1) / (y - 1)) + 1);
        r -= step;
        c += (c - 1) / (y - 1) * step;
        if (c > 1e12) {
            cout << "-1\n";
            return;
        }
    }
    cout << c << '\n';
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}