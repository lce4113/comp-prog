// Codeforces Round 1033: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (x1 == x2 && x2 == x3 && y1 + y2 + y3 == x1) {
        cout << "YES\n";
        return;
    }
    if (y1 == y2 && y2 == y3 && x1 + x2 + x3 == y1) {
        cout << "YES\n";
        return;
    }
    if (x1 == x2 + x3 && y2 == y3 && y1 + y2 == x1) {
        cout << "YES\n";
        return;
    }
    if (x2 == x1 + x3 && y1 == y3 && y1 + y2 == x2) {
        cout << "YES\n";
        return;
    }
    if (x3 == x1 + x2 && y1 == y2 && y1 + y3 == x3) {
        cout << "YES\n";
        return;
    }
    if (y1 == y2 + y3 && x2 == x3 && x1 + x2 == y1) {
        cout << "YES\n";
        return;
    }
    if (y2 == y1 + y3 && x1 == x3 && x1 + x2 == y2) {
        cout << "YES\n";
        return;
    }
    if (y3 == y1 + y2 && x1 == x2 && x1 + x3 == y3) {
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