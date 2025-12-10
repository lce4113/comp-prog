// Codeforces Hello 2025: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int l, r;
    cin >> l >> r;
    int c = 0;
    while (true) {
        int re = 1 << (int)log2(r);
        // cout << c << ' ';
        if (re - 2 >= l) {
            // cout << '\n';
            cout << c + re << ' ' << c + re - 1 << ' ' << c + re - 2 << '\n';
            return;
        }
        if (re - 1 >= l && re + 1 <= r) {
            // cout << '\n';
            cout << c + re << ' ' << c + re - 1 << ' ' << c + re + 1 << '\n';
            return;
        }
        l -= re, r -= re;
        c += re;
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}