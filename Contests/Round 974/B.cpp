// Codeforces Round 974: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    int r = (n + 1) / 2;
    int l = (n - k + 1) / 2;
    if ((r - l) % 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}