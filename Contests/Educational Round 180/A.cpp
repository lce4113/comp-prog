// Codeforces Educational Round 180: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int a, x, y;
    cin >> a >> x >> y;
    if (a < min(x, y) || a > max(x, y)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}