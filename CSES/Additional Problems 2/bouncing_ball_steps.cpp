// CSES Additional Problems II: Bouncing Ball Steps

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    n--, m--;
    int N = k / n, M = k / m, C = k / lcm(n, m);
    int x = N % 2 ? n + 1 - k % n : k % n + 1;
    int y = M % 2 ? m + 1 - k % m : k % m + 1;
    cout << x << ' ' << y << ' ' << N + M - C << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}