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
    vector<int> mx(5), dp(5);
    for (int i = 0; i < 5; i++) mx[i] = dp[i] = -1e9;
    mx[0] = 0;
    for (int i = 1; i <= n; i++) {
        string s, S = "narek";
        cin >> s;
        for (int j = 0; j < 5; j++) {
            int now = mx[j], p = j;
            for (int k = 0; k < m; k++) {
                if (int(S.find(s[k])) != -1) now--;
                if (s[k] == S[p]) {
                    p++;
                    if (p == 5) p = 0, now += 10;
                }
            }
            dp[p] = max(dp[p], now);
        }
        for (int j = 0; j < 5; j++) mx[j] = max(mx[j], dp[j]);
    }
    cout << max({mx[0], mx[1], mx[2], mx[3], mx[4]}) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}