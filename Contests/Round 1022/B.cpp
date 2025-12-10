// Codeforces Round 1022: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    // int K = k;
    // while (K) {
    //     cout << K % 2;
    //     K /= 2;
    // }
    // cout << '\n';
    if (n == 1 && k == 0) {
        cout << "-1\n";
        return;
    }
    int c = __builtin_popcount(k);
    if (n <= c) {
        cout << k << '\n';
        return;
    }
    if ((n - c) % 2 == 0) {
        cout << n - c + k << '\n';
        return;
    }
    if (n - c == 1) {
        int i = (k == 1 || k == 0) ? 2 : 1;
        cout << 2 * i + k << '\n';
        return;
    }
    int i = (k == 1 || k == 0) ? 2 : 1;
    cout << n - c - 1 + 2 * i + k << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}