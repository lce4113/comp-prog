// CSES Sorting & Searching: Missing Coin Sum

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
    sort(a.begin(), a.end());
    int sm = 0;
    for (auto x : a) {
        if (x > sm + 1) {
            cout << sm + 1 << '\n';
            return;
        }
        sm += x;
    }
    cout << sm + 1 << '\n';
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}