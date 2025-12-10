// CSES Interactive Problems: Permuted Binary Strings

#include <bits/stdc++.h>
using namespace std;

string q(string a) {
    cout << "? " << a << endl;
    string res;
    cin >> res;
    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int e = 1; e < n; e *= 2) {
        string a(n, '0');
        for (int i = 0; i < n; i++) {
            if ((i & e) == 0) continue;
            a[i] = '1';
        }
        string b = q(a);
        for (int i = 0; i < n; i++) {
            if (b[i] == '1') p[i] += e;
        }
    }
    cout << "! ";
    for (auto x : p) cout << x + 1 << ' ';
    cout << endl;
}