// Codeforces Round #968: Problem B

#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define f first
#define s second

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    // for (auto x : a) cout << x << " ";
    // cout << '\n';
    if (n % 2)
        cout << a[n / 2] << '\n';
    else
        cout << a[n / 2] << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}