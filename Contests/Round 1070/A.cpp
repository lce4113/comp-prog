// Codeforces Round 1070: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int mx = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= mx) mx = a[i], ans++;
    }
    cout << n - ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}