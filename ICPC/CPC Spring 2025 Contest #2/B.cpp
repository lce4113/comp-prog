// Spring 2025 Columbia University Local Contest
// Problem ?

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

const int MAXN = 1e6;
vector<int> lp(MAXN + 1), pr, lpr(MAXN + 1);

void solve() {
    int l, r;
    cin >> l >> r;
    int lst = -1, ans = -1;
    for (int i = l; i <= r; i++) {
        if (lp[i] == i) {
            // cout << i << ' ' << lst << '\n';
            if (lst != -1) {
                int d = i - lst;
                ans = (ans == -1 ? d : min(ans, d));
            }
            lst = i;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; pr[j] * i <= MAXN; j++) {
            lp[pr[j] * i] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }
    // int p = 2;
    // for (int i = 0; i <= MAXN; i++) {
    //     if (lp[i] == i) p = i;
    //     lpr[i] = p;
    // }

    int t = 1;
    cin >> t;
    while (t--) solve();
}