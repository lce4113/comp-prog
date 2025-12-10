// Codeforces Round 1035: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n == 2) {
        cout << "-1\n";
        return;
    }
    if (n % 2) {
        cout << l << '\n';
        return;
    }
    if (__lg(r) == __lg(l)) {
        cout << "-1\n";
        return;
    }
    int c = (1ll << (1 + __lg(l)));
    if (k >= n - 1) {
        cout << c << '\n';
        return;
    }
    cout << l << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}