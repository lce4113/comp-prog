// Codeforces Pinely Round 4: Problem A

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
    int mx = -1;
    for (int i = 0; i < n; i += 2) {
        mx = max(mx, a[i]);
    }
    cout << mx << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}