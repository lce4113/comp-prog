// Codeforces Round 974: Problem A

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int curr = 0, ans = 0;
    for (auto x : a) {
        if (x >= k)
            curr += x;
        else if (x == 0 && curr > 0)
            curr--, ans++;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}