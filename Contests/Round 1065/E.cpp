// Codeforces Round 1065: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    vector<int> m = {0, 1, 3, 9, 5, 6, 2, 7, 4, 8, 11, 10};
    for (int i = 0; i < n / 12; i++) {
        for (auto x : m) ans.push_back(i * 12 + x);
    }
    for (int j = n / 12 * 12; j <= n; j++) {
        ans.push_back(j);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}