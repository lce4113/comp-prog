// Codeforces Educational Round 177
// Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define s second
#define f first

const int MAXN = 1e18;
set<int> nums;
map<pair<int, int>, int> dp;

int calc(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    if (dp.count({n, k})) return dp[{n, k}];
    int c = *(--nums.upper_bound(n));
    int ans = 0;
    for (int i = k, num = n; i >= 0; i--, num -= c) {
        if (num < c) {
            ans += calc(num, i);
            break;
        }
        ans += calc(c - 1, i);
    }
    dp[{n, k}] = ans;
    return ans;
}

void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    cout << calc(r, k) - calc(l - 1, k) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i *= 4, i++) nums.insert(i);

    int t = 1;
    cin >> t;
    while (t--) solve();
}