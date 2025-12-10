// Educational Codeforces Round 179: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    int x = 0, i = 1;
    while (x < n) x = x * 2 + 1, i += 2;
    cout << i << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}