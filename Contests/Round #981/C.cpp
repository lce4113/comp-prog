#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    if (n % 2) {
        for (int i = n / 2 - 2; i >= 0; i--) {
            int k = n - i - 1;
            if (a[i] == a[i + 1] || a[k] == a[k - 1]) {
                int tmp = a[i];
                a[i] = a[k];
                a[k] = tmp;
            }
        }
    } else {
        for (int i = n / 2 - 1; i >= 0; i--) {
            int k = n - i - 1;
            if (a[i] == a[i + 1] || a[k] == a[k - 1]) {
                int tmp = a[i];
                a[i] = a[k];
                a[k] = tmp;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) ans++;
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}