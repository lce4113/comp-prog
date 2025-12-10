// Codeforces Educational Round 175: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;

    vector<int> pfs(1, 0);
    for (auto x : a) pfs.push_back(pfs.back() + x == '1');

    vector<int> ans(n + 1, 0);
    ans[0] = 1;
    for (int i = 0; i < n - 2; i++)
        if (pfs[i + 2] - pfs[i] <= 0) ans[i + 1]++;
    for (int i = 0; i < n - 3; i++)
        if (pfs[i + 3] - pfs[i] <= 1) ans[i + 2]++;
    for (int i = 0; i < n - 4; i++)
        if (pfs[i + 4] - pfs[i] <= 0) ans[i + 3]++;
    for (int i = 0; i < n - 5; i++)
        if (pfs[i + 5] - pfs[i] <= 0) ans[i + 4]++;

    for (int i = 5; i <= n; i++) {
        ans[i] += ans[i - 4] * (pfs[i] - pfs[i - 4] == 1);
    }

    int sm = 0;
    for (auto x : ans) sm += x;
    cout << sm << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}