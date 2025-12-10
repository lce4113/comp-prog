// CSES Intro Problems: Bit Strings

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

int binexp(int a, int b) {
    int res = 1;
    for (; b; a *= a, a %= MOD, b /= 2) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int32_t main() {
    int n;
    cin >> n;
    cout << binexp(2, n) << '\n';
}
