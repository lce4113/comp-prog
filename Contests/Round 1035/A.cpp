// Codeforces Round 1035: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    if (b < a) {
        if (a % 2 && b == a - 1) {
            cout << y << '\n';
            return;
        }
        cout << "-1\n";
        return;
    }
    if (x <= y) {
        cout << x * (b - a) << '\n';
        return;
    }
    if (a % 2 == 0 && b % 2) {
        cout << y * ((b - a + 1) / 2) + x * (b - a - (b - a + 1) / 2) << '\n';
        return;
    }
    cout << y * ((b - a) / 2) + x * (b - a - (b - a) / 2) << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}