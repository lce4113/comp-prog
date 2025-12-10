// Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long

bool eq(vector<int> a, vector<int> b) {
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> b = a;
    int x = pow(10, floor(log2(b[0]) / log2(10)));
    b[0] = 9 * x + b[0] % x;
    vector<int> c = b;
    sort(c.begin(), c.end());
    // for (auto y : b) cout << y << ' ';
    // cout << '\n';
    // for (auto y : c) cout << y << ' ';
    // cout << '\n';
    if (!eq(b, c)) {
        for (auto y : b) cout << y << ' ';
        cout << '\n';
        return;
    }
    b = a;
    x = pow(10, floor(log2(b[n - 1]) / log2(10)));
    b[n - 1] = x + b[n - 1] % x;
    c = b;
    sort(c.begin(), c.end());
    if (!eq(b, c)) {
        for (auto y : b) cout << y << ' ';
        cout << '\n';
        return;
    }
    cout << "impossible\n";
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
}