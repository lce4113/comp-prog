#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

// 4
// 5 2
// nn
// aa
// rr
// ee
// kk
// 1 5
// narek
// 1 4
// nare
// 5 7
// nrrarek
// nrnekan
// uuuuuuu
// ppppppp
// nkarekz

// 2
// 2 5
// nnnna
// aarek
// 2 4
// nnna
// arek

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(5, -1e9), mx(5, -1e9);
    mx[0] = 0;
    string na = "narek";
    for (int j = 1; j <= n; j++) {
        string a;
        cin >> a;
        for (int p = 0; p < 5; p++) {
            int curr = p, val = mx[p];
            for (int i = 0; i < m; i++) {
                // cout << a[i] << ' ' << na[curr] << ' ' << val << '\n';
                if (int(na.find(a[i])) != -1) val--;
                if (a[i] == na[curr]) {
                    curr++;
                    if (curr == 5) curr = 0, val += 10;
                }
            }
            dp[curr] = max(dp[curr], val);
        }
        for (int k = 0; k < 5; k++) mx[k] = max(mx[k], dp[k]);
    }
    // for (auto x : dp) {
    //     for (auto y : x) cout << y << ' ';
    //     cout << '\n';
    // }
    // cout << '\n';
    cout << max({mx[0], mx[1], mx[2], mx[3], mx[4]}) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}