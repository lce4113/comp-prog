#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, X;
    cin >> n >> X;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int sum = 0, mx = -1;
    for (auto x : a) {
        mx = max(mx, x);
        sum += x;
    }
    cout << fixed << setprecision(0);
    if (mx * X < sum) {
        cout << (int)ceil((double)sum / X) << '\n';
        return;
    }
    cout << mx << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}