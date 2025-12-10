// Codeforces Round 955: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < b) swap(a, b), swap(c, d);
    cout << (c < d ? "NO\n" : "YES\n");
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}