// Codeforces Round 1004: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int a, b;
    cin >> a >> b;
    if (a + 1 == b) {
        cout << "YES\n";
        return;
    }
    if ((a - b) % 9 == 8) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
