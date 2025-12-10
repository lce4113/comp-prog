// NWERC 2024: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, k;

int binexp(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= n) {
        if (b % 2) res *= a, res %= n;
    }
    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    string a;
    cin >> a;
    for (int i = 0; i < n; i++) {
        cout << a[binexp(2, k) * i % n];
    }
    cout << '\n';
}