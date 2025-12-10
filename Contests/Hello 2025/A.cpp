// Codeforces Hello 2025: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    int ans = 1 + b;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}