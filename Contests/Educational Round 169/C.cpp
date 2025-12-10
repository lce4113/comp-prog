// Codeforces Educational Round 169: Problem C

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
    sort(a.begin(), a.end());
    int sm = 0;
    for (auto x : a) sm += x;
    if (n % 2) {
        int sm1 = 0;
        for (int i = 0; i < n; i += 2) sm1 += a[i];
        int ans = abs((sm - sm1) - sm1);
        cout << max(a[0], ans - k) << '\n';
    } else {
        int sm1 = 0, sm2 = 0;
        for (int i = 0; i < n; i += 2) sm1 += a[i];
        for (int i = n - 1; i >= 0; i -= 2) sm2 += a[i];
        int d1 = abs((sm - sm1) - sm1), d2 = abs((sm - sm2) - sm2);
        int ans = max(d1, d2);
        cout << max(0ll, ans - k) << '\n';
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}