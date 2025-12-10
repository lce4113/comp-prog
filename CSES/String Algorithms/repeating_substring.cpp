// CSES String Algorithms: Repeating Substring

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const int MAXN = 1e5;
const int P = 53;
vector<int> pfs1(1, 0), pfs2(1, 0), ps1(MAXN + 1, 1), ps2(MAXN + 1, 1);
vector<string> ans(MAXN + 1);
string a;

int n;
int H(int h, int v, int m) { return (h * P + v) % m; }
int hi1(int l, int r) {
    return (pfs1[r] - pfs1[l] * ps1[r - l] % MOD1 + MOD1) % MOD1;
}
int hi2(int l, int r) {
    return (pfs2[r] - pfs2[l] * ps2[r - l] % MOD2 + MOD2) % MOD2;
}

bool check(int m) {
    set<pair<int, int>> st;
    for (int i = 0; i + m <= n; i++) {
        pair<int, int> hsh = {hi1(i, i + m), hi2(i, i + m)};
        if (st.count(hsh)) {
            ans[m] = a.substr(i, m);
            return 1;
        }
        st.insert(hsh);
    }
    return 0;
}

int32_t main() {
    cin >> a;
    n = a.size();
    for (auto v : a) pfs1.push_back(H(pfs1.back(), v - 'a', MOD1));
    for (auto v : a) pfs2.push_back(H(pfs2.back(), v - 'a', MOD2));
    for (int i = 1; i <= MAXN; i++) ps1[i] = ps1[i - 1] * P % MOD1;
    for (int i = 1; i <= MAXN; i++) ps2[i] = ps2[i - 1] * P % MOD2;
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    // cout << l << '\n';
    cout << (l == 0 ? "-1" : ans[l]) << '\n';
}