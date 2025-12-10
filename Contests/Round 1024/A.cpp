// Codeforces Round 1024: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    if (n % p) {
        cout << "YES\n";
        return;
    }
    if (n / p * q == m) {
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