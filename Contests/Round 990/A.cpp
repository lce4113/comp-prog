// Codeforces Round 990: Problem A

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
    int ans = 0, sm = 0;
    for (auto x : a) {
        sm += x;
        if (floor(sqrt(sm)) == sqrt(sm) && (int)sqrt(sm) % 2) ans++;
        // cout << sm << ' ';
    }
    // cout << '\n';
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}