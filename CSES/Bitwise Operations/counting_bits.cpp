// CSES Bitwise Operations: Counting Bits

#include <bits/stdc++.h>
using namespace std;

#define int long long

int count(int n) {
    if (n == 0) return 0;
    int l = __lg(n);
    int p = 1ll << l;
    return l * p / 2 + (n - p + 1) + count(n - p);
}

int32_t main() {
    int n;
    cin >> n;
    cout << count(n) << '\n';
}