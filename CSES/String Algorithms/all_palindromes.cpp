// CSES String Algorithms: All Palindromes

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int P = 53;
const int MAXN = 2e5;
int n;

vector<int> pfs1(1, 0), pfs2(1, 0), ps(MAXN + 1, 1);

int H(int h, int v) { return (h * P + v) % MOD; }
int hi1(int l, int r) {
    return (pfs1[r] - pfs1[l] * ps[r - l] % MOD + MOD) % MOD;
}
int hi2(int l, int r) {
    return (pfs2[r] - pfs2[l] * ps[r - l] % MOD + MOD) % MOD;
}

bool pal(int l, int r) {
    int m = (l + r) / 2;
    return hi1(l, m) == hi2(n - 1 - r, n - 1 - m);
}

int32_t main() {
    for (int i = 1; i <= MAXN; i++) ps[i] = ps[i - 1] * P % MOD;

    string b, a = "A";
    cin >> b;
    for (auto x : b) a += x, a += 'A';
    n = a.size();

    for (auto x : a) pfs1.push_back(H(pfs1.back(), x == 'A' ? 26 : x - 'a'));
    reverse(a.begin(), a.end());
    for (auto x : a) pfs2.push_back(H(pfs2.back(), x == 'A' ? 26 : x - 'a'));

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int l = 0, r = min(i + 1, n - i);
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (pal(i - m, i + m)) {
                l = m;
            } else {
                r = m;
            }
        }
        ans[i + l] = max(ans[i + l], 2 * l + 1);
    }

    for (int i = n - 2; i >= 0; i--) ans[i] = max(ans[i], ans[i + 1] - 2);
    for (int i = 1; i < n; i += 2) cout << max(ans[i], ans[i + 1]) / 2 << ' ';
    cout << '\n';
}