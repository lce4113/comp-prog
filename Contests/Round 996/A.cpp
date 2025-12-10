// Codeforces Round 996: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (b % 2 == a % 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}