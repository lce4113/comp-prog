#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> currpool;
    int ans = 0, mult = 1;
    int i = 1;
    while (a[i] < a[i + 1]) i++;
    for (; i < n - 1; i++) {
        if (a[i - 1] <= a[i] || a[i] > a[i + 1]) continue;
        int start = a[i - 1];
        int eq = a[i], num_eq = i;
        while (a[i] == a[i + 1]) i++;
        if (i >= n - 1 || a[i] > a[i + 1]) continue;
        num_eq = i - num_eq + 1;
        int end = a[i + 1];
        // cout << start << ' ' << end << ' ' << eq << ' ' << num_eq << '\n';
        int curr = (min(start, end) - eq) * num_eq;
        if (curr == ans) mult++;
        if (curr > ans) ans = curr, mult = 1;
    }
    cout << ans * mult << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}