// CSES Bitwise Operations: Number of Subset Xors

#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int basis = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        basis++;
        for (int j = i + 1; j < n; j++) {
            a[j] = min(a[j], a[i] ^ a[j]);
        }
    }
    cout << (1 << basis) << '\n';
}