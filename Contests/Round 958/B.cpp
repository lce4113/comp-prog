// Codeforces Round 958: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<char> a(n);
    for (auto &x : a) cin >> x;
    int c1 = 0, c0 = a[0] == '0';
    for (int i = 0; i < n; i++) {
        c1 += a[i] == '1';
        if (i != 0) c0 += a[i - 1] == '1' && a[i] == '0';
    }
    if (c1 > c0) {
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