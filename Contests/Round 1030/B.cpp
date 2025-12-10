// Codeforces Round 1030: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    cout << 2 * n - 1 << '\n';
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ' ' << i + 1 << ' ' << n << '\n';
        if (i != 0) cout << i + 1 << ' ' << 1 << ' ' << i << '\n';
    }
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}