// CSES Interactive Problems: Hidden Integer

#include <bits/stdc++.h>
using namespace std;

bool q(int n) {
    cout << "? " << n << endl;
    string a;
    cin >> a;
    return a == "YES";
}

int32_t main() {
    int l = 0, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (q(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << "! " << r << endl;
}