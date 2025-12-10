// CodeTON Round 9: Problem A

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    // cout << 0 << ' ';
    for (int i = 0; i < n; i++) cout << i + (i + 1) << ' ';
    cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}