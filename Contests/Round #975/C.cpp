#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;

int check(int num, int mx, int sum) { return (num * mx - sum) <= k; }

void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    int sum = 0;
    for (auto x : a) sum += x;
    int nk = 0;
    for (auto x : a) nk += a[0] - x;
    k = min(nk, k);
    int l = 1, r = (sum + k) / a[0] + 1, m = (l + r) / 2;
    for (; r - l > 1; m = (l + r) / 2) {
        if (check(m, a[0], sum)) {
            l = m;
        } else {
            r = m;
        }
    }
    if (l * a[0] < sum) {
        cout << 1 << '\n';
        return;
    }
    cout << l << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}