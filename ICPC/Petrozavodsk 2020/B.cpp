// Petrozavodsk 2020: Problem B

#include <bits/stdc++.h>
using namespace std;

const int B = 20;
const int N = 1 << B;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> sos(N);
    for (auto x : a) sos[x]++;
    // for (auto x : sos) cout << x << ' ';
    // cout << '\n';
    for (int b = 0; b < B; b++) {
        for (int i = N - 1; i >= 0; i--) {
            if (i & (1 << b)) sos[i] += sos[i ^ (1 << b)];
        }
        // for (auto x : sos) cout << x << ' ';
        // cout << '\n';
    }
    int ans = 0;
    for (auto x : a) ans += sos[x];
    cout << ans << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}