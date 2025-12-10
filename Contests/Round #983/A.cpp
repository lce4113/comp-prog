// Codeforces Round #983: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    int o = 0, z = 0;
    for (auto &x : a) {
        cin >> x;
        if (x == 1)
            o++;
        else
            z++;
    }
    cout << (o % 2) << ' ' << min(o, z) << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}