// CSES Bitwise Operations

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> comb(n), f(n);
    for (int i = 1; i < n; i++) f[i] = f[i - 1] + __builtin_ctz(i);
    for (int i = 0; i < n; i++) comb[i] = (f[n - 1] == f[i] + f[n - i - 1]);
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) ans ^= a[i] * comb[i];
    cout << ans << '\n';
}