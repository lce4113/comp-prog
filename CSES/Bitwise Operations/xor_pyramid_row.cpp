// CSES Bitwise Operations: XOR Pyramid Row

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, e, j, i = 0;
    cin >> n >> k;
    k = n - k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    for (e = 1; e <= k; e *= 2) {
        if (e & k)
            for (j = 0; j + e < n; j++) a[j] = a[j] ^ a[j + e];
    }
    for (; i < n - k; i++) cout << a[i] << ' ';
    cout << '\n';
}