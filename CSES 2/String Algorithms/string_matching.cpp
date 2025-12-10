// CSES String Algorithms: String Matching

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int P = 53;

int binexp(int a, int b) {
    int res = 1;
    for (; b; b /= 2, a *= a, a %= MOD) {
        if (b % 2) res *= a, res %= MOD;
    }
    return res;
}

vector<int> pfs(1, 0);

int H(int h, int nxt) { return (h * P + nxt) % MOD; }
int Hi(int l, int r) {
    return (pfs[r] - pfs[l] * binexp(P, r - l) % MOD + MOD) % MOD;
}

int32_t main() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    for (auto c : a) pfs.push_back(H(pfs.back(), c - 'a'));
    int B = 0;
    for (auto c : b) B = H(B, c - 'a');
    int ans = 0;
    for (int i = 0; i + m <= n; i++) {
        ans += B == Hi(i, i + m);
    }
    cout << ans << '\n';
}