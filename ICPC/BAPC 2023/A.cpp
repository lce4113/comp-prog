// BAPC 2023: Problem A

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    if (k + m >= n) {
        cout << "100\n";
        return 0;
    }
    sort(a.rbegin(), a.rend());
    double c = 0;
    for (int i = 0; i < m + k; i++) {
        c += a[i];
    }
    c /= reduce(a.begin(), a.end());
    c *= 100;
    cout << setprecision(10) << c << '\n';
}