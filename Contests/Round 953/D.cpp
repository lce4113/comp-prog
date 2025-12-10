// Codeforces Round 953: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) ans[i] = i;
    int mxi = 0;
    a[0] += c;
    for (int i = 0; i < n; i++) {
        if (a[i] > a[mxi]) mxi = i;
    }
    ans[mxi] = 0;
    a[0] -= c;
    int sm = c;
    for (int i = 0; i < mxi; i++) {
        sm += a[i];
        if (a[mxi] > sm) ans[i]++;
    }
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}