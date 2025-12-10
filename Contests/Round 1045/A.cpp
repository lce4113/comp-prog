// Codeforces Round 1045: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n % 2 == a % 2 && n % 2 == b % 2) {
        cout << "YES\n";
        return;
    }
    if (n % 2 == b % 2 && a < b) {
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