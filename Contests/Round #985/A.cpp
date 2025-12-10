// Codeforces Round 985: Problem A

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    int x = r / k;
    cout << max(0, x - l + 1) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}