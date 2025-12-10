// Codeforces Global Round 29: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "1 1\n";
        return;
    }
    if (n == 2) {
        cout << "1 2 1 2\n";
        return;
    }
    vector<int> a(2 * n);
    if (n % 2) {
        for (int l = 0, r = n - 1, c = n - 1; r > l; r--, l++, c -= 2) {
            a[l] = c, a[r] = c;
        }
        a[n / 2] = n, a[n / 2 + n] = n;
        a[2 * n - 1] = 1, a[n / 2 + n - 1] = 1;
        for (int l = n, r = 2 * n - 2, c = n - 2; c > 1; r--, l++, c -= 2) {
            a[l] = c, a[r] = c;
        }
    } else {
        for (int l = 0, r = n, c = n; r > l; r--, l++, c -= 2) {
            a[l] = c, a[r] = c;
        }
        a[n / 2] = n - 1, a[n / 2 + n - 1] = n - 1;
        a[n / 2 + n] = 1, a[2 * n - 1] = 1;
        for (int l = n + 1, r = 2 * n - 2, c = n - 3; c > 1; r--, l++, c -= 2) {
            a[l] = c, a[r] = c;
        }
    }
    for (auto x : a) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}