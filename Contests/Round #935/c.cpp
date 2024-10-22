// CodeForces Round #935: Problem C

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int one = 0, zero = 0;
    vector<int> pfs_f;
    for (int i = 0; i < n; i++) {
        pfs_f.push_back(zero >= one);
        if (s[i] == '1') {
            one++;
        } else {
            zero++;
        }
    }
    pfs_f.push_back(zero >= one);
    one = 0, zero = 0;
    vector<int> pfs_b;
    for (int i = n - 1; i >= 0; i--) {
        pfs_b.push_back(one >= zero);
        if (s[i] == '1') {
            one++;
        } else {
            zero++;
        }
    }
    pfs_b.push_back(one >= zero);
    // for (auto x : pfs_f) cout << x << ' ';
    // cout << '\n';
    // for (auto x : pfs_b) cout << x << ' ';
    // cout << '\n';
    int mn = INT_MAX, mi;
    for (int i = 0; i <= n; i++) {
        if (pfs_f[i] && pfs_b[n - i] && abs((double)n / 2 - i) < mn) {
            mn = abs((double)n / 2 - i);
            mi = i;
        }
    }
    cout << mi << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}