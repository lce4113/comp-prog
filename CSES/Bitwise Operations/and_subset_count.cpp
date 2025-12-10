// CSES Bitwise Operations: And Subset Count

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int MAXN = 2e5;
const int B = 20;

int binexp(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<int>> sup(B + 1, vector<int>(MAXN + 1));
    for (auto x : a) sup[0][x]++;

    // for (int i = 0; i <= n; i++) cout << sup[0][i] << ' ';
    // cout << '\n';

    for (int j = MAXN; j >= 0; j--) {
        for (int i = 1; i <= B; i++) {
            int e = 1 << (i - 1);
            sup[i][j] = sup[i - 1][j];
            if ((j & e) == 0 && (j ^ e) <= MAXN) sup[i][j] += sup[i - 1][j ^ e];
        }
    }
    sup[0] = sup[B];
    for (auto &x : sup[0]) x = (binexp(2, x) - 1 + MOD) % MOD;
    for (int j = MAXN; j >= 0; j--) {
        for (int i = 1; i <= B; i++) {
            int e = 1 << (i - 1);
            sup[i][j] = sup[i - 1][j];
            if ((j & e) == 0 && (j ^ e) <= MAXN)
                sup[i][j] += MOD - sup[i - 1][j ^ e], sup[i][j] %= MOD;
        }
    }

    for (int i = 0; i <= n; i++) cout << sup[B][i] << ' ';
    cout << '\n';
}