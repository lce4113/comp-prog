// CSES String Algorithms: Finding Borders

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int P = 53;
vector<int> pfs(1, 0);

int binexp(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

int H(int h, int nxt) { return (h * P + nxt) % MOD; }
int Hi(int l, int r) {
    return (pfs[r] - pfs[l] * binexp(P, r - l) % MOD + MOD) % MOD;
}

int32_t main() {
    string a;
    cin >> a;
    int n = a.size();
    for (auto c : a) pfs.push_back(H(pfs.back(), c));
    for (int i = 1, j = n - 1; j > 0; i++, j--) {
        if (Hi(0, i) == Hi(j, n)) cout << i << ' ';
    }
    cout << '\n';
}