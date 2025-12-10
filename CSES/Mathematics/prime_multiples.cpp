// CSES Mathematics: Prime Multiples

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (auto &x : a) cin >> x;
    int ans = 0;
    for (int i = 1; i < (1 << k); i++) {
        int prod = 1;
        bool ok = 1;
        for (int j = 0; j < k; j++) {
            if ((i & (1 << j)) == 0) continue;
            if (n / a[j] < prod) {
                ok = 0;
                break;
            }
            prod *= a[j];
        }
        if (!ok) continue;
        ans += (n / prod) * (__builtin_parity(i) ? 1 : -1);
    }
    cout << ans << '\n';
}