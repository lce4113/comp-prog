#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int a, b;
    cin >> a >> b;
    cout << max(min(a, 2 * a - b), 0) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}