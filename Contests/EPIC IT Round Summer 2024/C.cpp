// EPIC IT Round Summer 2024: Problem C

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
    reverse(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) a[i + 1] = max(a[i + 1], a[i] + 1);
    cout << a.back() << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}