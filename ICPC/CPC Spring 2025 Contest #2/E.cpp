// Spring 2025 Columbia University Local Contest
// Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    long double n, px, qx, py, qy;
    cin >> n >> px >> qx >> py >> qy;
    cout << n * (px - qx) << ' ' << n * (py - qy) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}