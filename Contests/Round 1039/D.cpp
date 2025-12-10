// Codeforces Round 1039: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> lds(n), ans(n);
    lds[0] = 1, ans[0] = 1;
    lds[1] = 1, ans[1] = 2;
    if (a[1] < a[0]) lds[1] = 2, ans[1] = 3;
    for (int i = 2; i < n; i++) {
        if (a[i - 1] > a[i] && a[i - 2] > a[i]) {
            if (lds[i - 1] > lds[i - 2]) {
                lds[i] = lds[i - 1] + 1;
                ans[i] = ans[i - 1] + i + 1;
            } else {
                lds[i] = lds[i - 2] + 1;
                ans[i] = ans[i - 2] + i + 1;
            }
        }
        if (a[i - 1] > a[i]) {
            lds[i] = lds[i - 1] + 1;
            ans[i] = ans[i - 1] + i + 1;
        } else {
            lds[i] = lds[i - 2] + 1;
            ans[i] = ans[i - 2] + i + 1;
        }
    }
    // for (auto x : ans) cout << x << ' ';
    // cout << '\n';
    cout << reduce(ans.begin(), ans.end()) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}