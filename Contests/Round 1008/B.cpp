// Codeforces Round 1008: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    if (k % 2) {
        for (int i = 0; i < n - 1; i++) {
            cout << n << ' ';
        }
        cout << n - 1 << '\n';
        return;
    }
    for (int i = 0; i < n - 2; i++) {
        cout << n - 1 << ' ';
    }
    cout << n << ' ';
    cout << n - 1 << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}