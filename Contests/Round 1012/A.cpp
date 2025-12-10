// Codeforces Round 1012: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int x, y, a;
    cin >> x >> y >> a;
    a %= x + y;
    cout << (a >= x ? "YES\n" : "NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}