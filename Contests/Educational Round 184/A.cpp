// Codeforces Educational Round 184: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define f first
#define s second

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int p = --lower_bound(a.begin(), a.end(), k) - a.begin();
    int P = a.end() - upper_bound(a.begin(), a.end(), k);
    if (p > P - 1) {
        cout << k - 1 << '\n';
    } else {
        cout << k + 1 << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}