// CodeForces Round #970: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> x;
    x.push_back(a);
    x.push_back(b);
    x.push_back(c);
    x.push_back(d);
    sort(x.begin(), x.end());
    if (x[0] == a && x[3] == d) {
        cout << "YES\n";
        return;
    }
    if (x[0] == d && x[3] == a) {
        cout << "YES\n";
        return;
    }
    if (x[0] == b && x[3] == c) {
        cout << "YES\n";
        return;
    }
    if (x[0] == c && x[3] == b) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) solve();
}