// Codeforces Round 961: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> diag;
    for (int i = 1; i < n; i++) {
        diag.push_back(i);
        diag.push_back(i);
    }
    diag.push_back(n);
    sort(diag.rbegin(), diag.rend());
    int ans = 0;
    if (k == 0) {
        cout << ans << '\n';
        return;
    }
    for (auto x : diag) {
        k -= x, ans++;
        if (k <= 0) break;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}