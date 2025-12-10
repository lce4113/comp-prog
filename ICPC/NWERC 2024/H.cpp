// NWERC 2024: Problem H

#include <bits/stdc++.h>
using namespace std;

int q(int c, int r) {
    cout << "? " << c << ' ' << r << endl;
    int v;
    cin >> v;
    return v;
}

void res(int c, int r) { cout << "! " << c << ' ' << r << endl; }

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    int v = q(n, 1);
    if (v == n) {
        res(n, 1);
    } else {
        res(v, q(n - v, 1));
    }
}