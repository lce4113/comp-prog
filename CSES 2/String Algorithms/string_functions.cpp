// CSES String Algorithms: String Functions

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int P = 53;
const int MAXN = 1e6;
vector<int> pfs(1, 0), ps(MAXN + 1, 1);
string a;
int n;

int H(int h, int v) { return (h * P + v) % MOD; }
int hi(int l, int r) { return (pfs[r] - pfs[l] * ps[r - l] % MOD + MOD) % MOD; }

int32_t main() {
    cin >> a;
    n = a.size();

    for (int i = 1; i <= MAXN; i++) ps[i] = ps[i - 1] * P % MOD;
    for (auto c : a) pfs.push_back(H(pfs.back(), c - 'a'));

    vector<int> z(n), pi(n);
    z[0] = 0;
    for (int i = 1; i < n; i++) {
        int l = 0, r = n - i + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (hi(0, m) == hi(i, i + m)) {
                l = m;
            } else {
                r = m;
            }
        }
        z[i] = l, pi[i + l - 1] = max(pi[i + l - 1], l);
    }
    for (int i = n - 2; i >= 0; i--) {
        pi[i] = max(pi[i + 1] - 1, pi[i]);
    }

    for (auto x : z) cout << x << ' ';
    cout << '\n';
    for (auto x : pi) cout << x << ' ';
    cout << '\n';
}