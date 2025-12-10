// ICPC Pacific Northwest Regional 2018-19
// Problem B: Coprime Integers

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e7;

vector<array<int, 3>> lp(MAXN + 1, {0, 0});
vector<int> pr;

void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    int ans = (r1 - l1 + 1) * (r2 - l2 + 1);
    for (int i = 2; i <= r1; i++) {
        if (lp[i][1]) continue;
        int c1 = r1 / i - (l1 - 1) / i, c2 = r2 / i - (l2 - 1) / i;
        ans += c1 * c2 * (lp[i][2] % 2 ? -1 : 1);
    }

    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= MAXN; i++) {
        if (lp[i][0] == 0) {
            lp[i] = {i, 0, 1};
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= MAXN; j++) {
            lp[pr[j] * i] = {pr[j], lp[i][1] || pr[j] == lp[i][0],
                             lp[i][2] + 1};
            if (pr[j] == lp[i][0]) break;
        }
    }

    int t = 1;
    while (t--) solve();
}
