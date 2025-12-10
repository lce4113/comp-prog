// Codeforces Global Round 29: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long

int binexp(int a, int b, int m) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= m) {
        if (b % 2) res *= a, res %= m;
    }
    return res;
}

bool check(int a, int m) {
    if (a % m == 0) return 0;
    int e = binexp(a, a, m - 1);
    // cout << a << ' ' << e << '\n';
    return (binexp(a, e, m) == 1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int c = 0;
    for (int i = 1; i <= 506; i++) {
        if (check(i, 23) && i % 22 != 0 && i % 23 != 1) {
            cout << i << '\n';
            c++;
        }
    }
    cout << "c: " << c << '\n';

    // int t = 1;
    // cin >> t;
    // while (t--) solve();
}