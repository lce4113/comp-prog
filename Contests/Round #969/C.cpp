// Codeforces Round #969: Problem C

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (auto &X : a) cin >> X;
    int g = gcd(x, y);
    set<int> ms;
    for (auto X : a) ms.insert(X % g);
    ms.insert(*ms.begin() + g);
    // for (auto x : ms) cout << x << ' ';
    // cout << '\n';
    int mxd = 0;
    for (auto it = ms.begin(); it != ms.end(); it++) {
        auto it2 = it;
        it2++;
        if (it2 == ms.end()) break;
        mxd = max(mxd, *it2 - *it);
    }
    cout << (g - mxd) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}
