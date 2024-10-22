// CodeForces Round #973: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long

bool bin(int m, int mi, vector<int> a, int n) {
    int curr = 0;
    for (int i = 0; i < n; i++) {
        // if (i == mi) continue;
        curr += a[i] - m;
        if (curr < 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int mx = -1, mi;
    for (int i = 0; i < n; i++) {
        if (a[i] > mx) mx = a[i], mi = i;
    }
    // cout << "mx: " << mx << ", " << "mi: " << mi << '\n';
    int l = 1, r = mx;
    int i = 0;
    for (int m = (l + r) / 2; r - l > 1; i++) {
        if (i > 100) break;
        if (!bin(m, mi, a, n)) {
            cout << m << " no" << '\n';
            r = m;
        } else {
            l = m;
        }
        m = (l + r) / 2;
        cout << "l: " << l << ", " << "r: " << r << ", " << "m: " << m << '\n';
    }
    cout << mx - l << '\n';
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}