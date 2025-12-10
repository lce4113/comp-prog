// CSES Mathematics: Nim Game II

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        ans ^= x % 4;
    }
    cout << (ans == 0 ? "second\n" : "first\n");
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}