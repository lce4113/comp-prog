#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int a = ceil((double)k / sqrt(2));
    cout << "0 0 " << a << ' ' << a << '\n';
    cout << a << " 0 0 " << a << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}