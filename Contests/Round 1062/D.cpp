#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e7;
vector<int> lp(N + 1), pr;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    set<int> rem;
    int ans = 1e18;
    for (auto x : a) {
        int c = 0;
        for (auto p : pr) {
            if (x % p) {
                c = p;
                break;
            }
        }
        ans = min(ans, c);
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i <= N; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; pr[j] * i <= N; j++) {
            lp[pr[j] * i] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}