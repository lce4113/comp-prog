// Codeforces Global Round 28: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> b(m);
    for (auto &x : b) cin >> x;

    int k = a[0];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> b2;
    for (auto x : b) {
        int pos = x <= k ? 0 : a.end() - lower_bound(a.begin(), a.end(), x);
        b2.push_back(pos);
    }

    // for (auto x : b) cout << x << ' ';
    // cout << '\n';

    sort(b2.begin(), b2.end());

    // cout << "b2: ";
    // for (auto x : b2) cout << x << ' ';
    // cout << '\n';

    // vector<int> b2pfs(m + 1, 0);
    // for (int i = 0; i < m; i++) b2pfs[i + 1] = b2pfs[i] + b2[i];

    // for (auto x : b2pfs) cout << x << ' ';
    // cout << '\n';

    vector<int> ans(m + 1, 0);
    for (int i = 1; i <= m; i++) ans[i] += m / i;

    // cout << "ans: ";
    // for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    // cout << '\n';

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (i % j) continue;
            ans[j] += b2[i - 1];
            if (j * j != i) ans[i / j] += b2[i - 1];
            // cout << i << ' ' << j << ' ' << ans[j] << ' ' << b2[i - 1] <<
            // '\n'; cout << i << ' ' << j << ' ' << ans[i / j] << ' ' << b2[i -
            // 1]
            //      << '\n';
        }
    }

    // cout << "ans: ";
    for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}