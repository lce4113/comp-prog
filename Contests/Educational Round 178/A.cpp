// Codeforces Educational Round 178: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 3) {
        cout << "NO\n";
        return;
    }
    if (a > (a + b + c) / 3 || b > (a + b + c) / 3) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}