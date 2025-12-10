// Codeforces Round 994: Problem A

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = (a[0] != 0);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 0 && a[i + 1] != 0) ans++;
    }
    cout << min(2, ans) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}