// CSES Mathematics: Josephus Queries

#include <bits/stdc++.h>
using namespace std;

int q(int l, int r, int step, bool second, int k) {
    int tot = (r - l) / step + 1;
    int count = (tot - second + 1) / 2;

    if (k <= count) return l + second * step + 2 * step * (k - 1);

    int next_l = second ? l : l + step;
    int next_r = (tot - second) % 2 ? r - step : r;
    bool next_second = (tot - second) % 2;

    return q(next_l, next_r, 2 * step, next_second, k - count);
}

void solve() {
    int n, k;
    cin >> n >> k;
    cout << q(1, n, 1, 1, k) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}