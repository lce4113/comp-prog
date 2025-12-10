// Codeforces Global Round 28: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;

    set<int> nums;
    for (int i = 1; i <= n; i++) nums.insert(i);

    vector<int> ans(n, 0);
    for (int i = k - 1, num = 1; i < n; num++, i += k) {
        ans[i] = num;
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) {
            ans[i] = *nums.rbegin();
            nums.erase(*nums.rbegin());
        }
    }

    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}