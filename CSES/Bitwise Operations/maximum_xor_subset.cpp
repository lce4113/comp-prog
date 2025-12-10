// CSES Bitwise Operations: Maximum Xor Subset

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> basis;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        basis.push_back(a[i]);
        for (int j = i + 1; j < n; j++) {
            a[j] = min(a[j], a[j] ^ a[i]);
        }
    }

    int ans = 0;
    for (auto x : basis) {
        if ((ans ^ x) > ans) ans ^= x;
    }
    cout << ans << '\n';
}
