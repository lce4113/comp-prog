// Codeforces Global Round 29: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int a, b;
    cin >> a >> b;
    if (a < b) {
        cout << "2\n";
        return;
    }
    if (b == 1 || a - 1 <= b) {
        cout << "-1\n";
        return;
    }
    cout << "3\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}