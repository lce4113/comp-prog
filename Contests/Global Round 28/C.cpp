// Codeforces Global Round 28: Problem C

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    string a;
    cin >> a;
    int n = a.size();

    // set<int> lr;
    // for (int i = 1; i <= n; i++) lr.insert(i);

    int c1 = 0, c0 = 0, i = 0;
    while (i < n && a[i] == '1') c1++, i++;
    while (i < n && a[i] == '0') c0++, i++;
    // vector<pair<int, int>> oz;
    // for (int i = 0; i < n;) {
    //     oz.push_back({c1, c0});
    //     int l = min(c1, c0), r = c1;
    //     // cout << "lr: " << l << ' ' << r << '\n';
    //     if (*lr.rbegin() < l || *lr.begin() > r) break;

    //     // for (auto x : lr) cout << x << ' ';
    //     // cout << '\n';

    //     vector<int> er;
    //     for (auto x : lr) {
    //         if (x > r || x < l) er.push_back(x);
    //     }
    //     for (auto x : er) lr.erase(x);
    // }

    // cmax, cl, cr for (int i = 0; i < n; i++) {}

    if (c1 <= c0) {
        cout << 1 << ' ' << n << ' ';
        cout << 1 << ' ' << n - c1 << '\n';
    } else {
        cout << 1 << ' ' << n << ' ';
        cout << min(n, c1 - c0 + 1) << ' ' << n - c0 << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}