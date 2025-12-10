// Codeforces Round 1008: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (auto &x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    int sm = 0;
    vector<int> ans(2 * n + 1);
    for (int i = 0; i < n + 1; i++) ans[2 * i] = a[i], sm += a[i];
    for (int i = n + 1; i < 2 * n; i++)
        ans[(i - n - 1) * 2 + 3] = a[i], sm -= a[i];
    ans[1] = sm;
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}