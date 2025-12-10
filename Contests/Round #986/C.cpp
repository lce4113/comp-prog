// Codeforces Round #986: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

int check(vector<int> a, int m, int v) {
    int n = a.size();
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    int ans = -1;

    vector<int> f(m + 1), g(m + 1);
    for (int i = 1, j = 0; i <= m; i++) {
        while (j <= n && pre[j] - pre[f[i - 1]] < v) {
            j++;
        }
        f[i] = j;
    }
    g[0] = n;
    for (int i = 1, j = n; i <= m; i++) {
        while (j >= 0 && pre[g[i - 1]] - pre[j] < v) {
            j--;
        }
        g[i] = j;
    }

    for (int i = 0; i <= m; i++) {
        if (f[i] <= g[m - i]) {
            ans = max(ans, pre[g[m - i]] - pre[f[i]]);
        }
    }
    return ans;
}

void solve() {
    // int solve(vector<int> a, int m, int v) {
    int n, m, v;
    cin >> n >> m >> v;
    // int n = a.size();
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> pfs(n + 1, 0), rpfs(n + 1, 0);
    for (int i = 0; i < n; i++) pfs[i + 1] = pfs[i] + a[i];
    for (int i = 0; i < n; i++) rpfs[i + 1] = rpfs[i] + a[n - i - 1];
    // for (auto x : pfs) cout << x << ' ';
    // cout << '\n';
    // for (auto x : rpfs) cout << x << ' ';
    // cout << '\n';
    vector<int> f(1, 0), r(1, 0);
    for (int i = 0; i <= n; i++)
        if (pfs[i] - pfs[f.back()] >= v) f.push_back(i);
    for (int i = 0; i <= n; i++)
        if (rpfs[i] - rpfs[r.back()] >= v) r.push_back(i);

    // for (auto x : f) cout << x << ' ';
    // cout << '\n';
    // for (auto x : r) cout << x << ' ';
    // cout << '\n';

    int ans = -1;
    for (int i = 0; i <= m; i++) {
        if (i >= (int)f.size() || (m - i) >= (int)r.size()) continue;
        // cout << f[i] << ' ' << r[m - i] << '\n';
        ans = max(ans, pfs[n] - pfs[f[i]] - rpfs[r[m - i]]);
    }
    cout << ans << '\n';
    // return ans;
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
    // for (int i1 = 1; i1 <= 4; i1++) {
    //     for (int i2 = 1; i2 <= 4; i2++) {
    //         for (int i3 = 1; i3 <= 4; i3++) {
    //             vector<int> a = {i1, i2, i3};
    //             for (auto x : a) cout << x << ' ';
    //             cout << '\n';
    //             int a1 = check(a, 2, 2), a2 = solve(a, 2, 2);
    //             cout << a1 << ' ' << a2 << '\n';
    //             if (a1 != a2) {
    //                 cout << "ohno but WE DID IT GANG\n";
    //                 return 0;
    //             }
    //         }
    //     }
    // }
}
