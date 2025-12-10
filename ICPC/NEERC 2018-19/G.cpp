#include <bits/stdc++.h>
using namespace std;

int k;
vector<int> w(7);

int calc(int i) {
    int K = k;
    int tot = reduce(w.begin(), w.end());
    int res = 0;
    for (int j = i; j < 7; j++) {
        res++, K -= w[j];
        if (K == 0) return res;
    }
    int rep = (K - 1) / tot;
    res += 7 * rep, K -= tot * rep;
    for (int j = 0; K; j++) res++, K -= w[j];
    return res;
}

void solve() {
    cin >> k;
    for (auto &x : w) cin >> x;
    int ans = 1e9;
    for (int i = 0; i < 7; i++) ans = min(ans, calc(i));
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}