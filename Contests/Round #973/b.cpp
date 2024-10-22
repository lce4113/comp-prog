// CodeForces Round #973: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto &x : a) {
        cin >> x;
        sum += x;
    }
    int red = sum - a[n - 1] - a[n - 2];
    int ans = a[n - 1] - (a[n - 2] - red);
    cout << ans << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}