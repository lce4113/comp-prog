// Codeforces Educational Round 178: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;

    vector<vector<int>> lst(n + 1, vector<int>(k, n));
    vector<int> dp(n + 2, 1e9);
    dp[n + 1] = 0, dp[n] = 1;
    for (int i = n - 1; i >= 0; i--) {
        lst[i] = lst[i + 1];
        lst[i][a[i] - 'a'] = i;
        int p = *max_element(lst[i].begin(), lst[i].end());
        dp[i] = dp[p + 1] + 1;
        // for (auto x : lst[i]) cout << x << ' ';
        // cout << '\n';
    }
    // for (auto x : dp) cout << x << ' ';
    // cout << '\n';

    int q;
    cin >> q;
    while (q--) {
        string c;
        cin >> c;
        int i = 0, ok = 1;
        for (auto ch : c) {
            // cout << i << ' ' << ch << ' ' << lst[i][ch - 'a'] << '\n';
            i = lst[i][ch - 'a'] + 1;
            if (i == n + 1) {
                cout << "0\n";
                ok = 0;
                break;
            }
        }
        if (ok) cout << dp[i] << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}