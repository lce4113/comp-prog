// Problem G

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ones = 0, l_two = 0, two_sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            ones++;
        } else if (a[i] == 2) {
            l_two = (two_sum + ones) % MOD;
            two_sum = (two_sum + l_two) % MOD;
        } else {
            ans = (ans + two_sum) % MOD;
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}