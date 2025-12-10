// CSES String Algorithms: Finding Periods

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const int P = 53;
const int MAXN = 1e6;
vector<int> ps1(MAXN + 1, 1), ps2(MAXN + 1, 1);
vector<int> pfs1(1, 0), pfs2(1, 0);
int n;

int H1(int h, int nxt) { return (h * P + nxt) % MOD1; }
int Hi1(int l, int r) {
    return (pfs1[r] - pfs1[l] * ps1[r - l] % MOD1 + MOD1) % MOD1;
}
int H2(int h, int nxt) { return (h * P + nxt) % MOD2; }
int Hi2(int l, int r) {
    return (pfs2[r] - pfs2[l] * ps2[r - l] % MOD2 + MOD2) % MOD2;
}
bool comp(int l1, int r1, int l2, int r2) {
    return Hi1(l1, r1) == Hi1(l2, r2) && Hi2(l1, r1) == Hi2(l2, r2);
}

bool check(int per) {
    int i = per;
    for (; i + per <= n; i += per) {
        if (!comp(i, i + per, 0, per)) return 0;
    }
    if (!comp(i, n, 0, n - i)) return 0;
    return 1;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) ps1[i] = ps1[i - 1] * P % MOD1;
    for (int i = 1; i <= MAXN; i++) ps2[i] = ps2[i - 1] * P % MOD2;

    string a;
    cin >> a;
    n = a.size();
    for (auto c : a) pfs1.push_back(H1(pfs1.back(), c - 'a'));
    for (auto c : a) pfs2.push_back(H2(pfs2.back(), c - 'a'));

    for (int i = 1; i <= n; i++) {
        if (check(i)) cout << i << ' ';
    }
    cout << '\n';
}