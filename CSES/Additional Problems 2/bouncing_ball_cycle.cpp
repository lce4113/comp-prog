// CSES Additional Problems II: Bouncing Ball Cycle

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    n--, m--;
    int t = lcm(2 * n, 2 * m);
    cout << t << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}