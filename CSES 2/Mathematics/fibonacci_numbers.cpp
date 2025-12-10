// CSES Mathematics: Fibonacci Numbers

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

// 0 1
// 2 3

vector<int> mul(vector<int> a, vector<int> b) {
    return {
        (a[0] * b[0] + a[1] * b[2]) % MOD, (a[0] * b[1] + a[1] * b[3]) % MOD,
        (a[2] * b[0] + a[3] * b[2]) % MOD, (a[2] * b[1] + a[3] * b[3]) % MOD};
}

int32_t main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0\n";
        return 0;
    }
    n--;
    vector<int> mat = {1, 1, 1, 0}, res = {1, 0, 0, 1};
    for (; n; n /= 2, mat = mul(mat, mat)) {
        if (n % 2) res = mul(mat, res);
    }
    cout << res[0] << '\n';
}