// CSES Mathematics: Bracket Sequences II

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int MAXN = 1e6;

vector<int> f(MAXN + 1, 1), rf(MAXN + 1, 1);

int binexp(int a, int b = MOD - 2) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int32_t main() {
    for (int i = 1; i <= MAXN; i++) f[i] = f[i - 1] * i, f[i] %= MOD;
    for (int i = 1; i <= MAXN; i++) rf[i] = binexp(f[i]);
    int n;
    cin >> n;
    string a;
    cin >> a;
    if (n % 2) {
        cout << "0\n";
        return 0;
    }
    int m = a.size();
    int cl = 0, cr = 0;
    for (auto x : a) {
        cl += x == '(';
        cr += x == ')';
        if (cl - cr < 0) {
            cout << "0\n";
            return 0;
        }
    }
    if (cl > n / 2) {
        cout << "0\n";
        return 0;
    }
    int c1 = f[n - m];
    c1 *= rf[n / 2 - cl], c1 %= MOD;
    c1 *= rf[n / 2 - cr], c1 %= MOD;
    if (n / 2 - 1 - cl < 0) {
        cout << c1 << '\n';
        return 0;
    }
    int c2 = f[n - m];
    c2 *= rf[n / 2 + 1 - cr], c2 %= MOD;
    c2 *= rf[n / 2 - 1 - cl], c2 %= MOD;
    cout << (c1 - c2 + MOD) % MOD << '\n';
}