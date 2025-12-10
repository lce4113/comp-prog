// Codeforces Educational Round 182: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    int ans = 2;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1] && a[i] > b[i + 1]) {
            cout << "0\n";
            return;
        }
        if (b[i] > a[i + 1] && b[i] > b[i + 1]) {
            cout << "0\n";
            return;
        }
        if (a[i] > a[i + 1] || a[i] > b[i + 1]) {
            continue;
        }
        if (b[i] > a[i + 1] || b[i] > b[i + 1]) {
            continue;
        }
        ans *= 2, ans %= MOD;
    }
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}