// Codeforces Round 951: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int L = 1, tot = 0;
    for (auto x : a) L = lcm(L, x);
    for (auto x : a) tot += L / x;
    if (tot < L) {
        for (auto x : a) cout << L / x << ' ';
        cout << '\n';
    } else {
        cout << "-1\n";
    }

    // int c = 0, tot = n;
    // while (tot >= c) {
    //     if (c == tot) tot++;
    //     if (tot >= 1e4) {
    //         cout << "-1\n";
    //         return;
    //     }
    //     c = tot, tot = 0;
    //     for (auto x : a) tot += (c - 1) / x + 1;
    //     // cout << "c: " << c << ' ' << tot << '\n';
    // }

    // for (auto x : a) cout << (tot - 1) / x + 1 << ' ';
    // cout << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}