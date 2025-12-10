// Codeforces Round 1001: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    string a;
    cin >> a;
    int ans = 0;
    for (auto x : a)
        if (x == '1') ans++;
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}