// Codeforces Educational Round 172: Problem A

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
    sort(a.rbegin(), a.rend());
    int sm = 0;
    for (int i = 0; i < n; i++) {
        sm += a[i];
        if (sm > k) {
            int ans = 0;
            cout << (k - (sm - a[i])) << '\n';
            return;
        }
    }
    cout << (k - sm) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}