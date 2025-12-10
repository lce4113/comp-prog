// CSES Dynamic Programming: Money Sums

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
    set<int> c;
    c.insert(0);
    for (auto x : a) {
        set<int> nxt;
        for (auto y : c) nxt.insert(y + x);
        for (auto y : nxt) c.insert(y);
    }
    c.erase(0);
    cout << c.size() << '\n';
    for (auto x : c) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}