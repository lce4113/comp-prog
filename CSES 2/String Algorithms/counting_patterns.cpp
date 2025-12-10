// CSES String Algorithms: Counting Patterns

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int P = 53;
const int MAXN = 1e5;
vector<int> pfs(1, 0), ps(MAXN + 1, 1);
string a;
int n;

int H(int h, int v) { return (h * P + v) % MOD; }
int hi(int l, int r) { return (pfs[r] - pfs[l] * ps[r - l] % MOD + MOD) % MOD; }

bool cmp(int l1, int r1, int l2, int r2) {
    int l = 0, r = min(r1 - l1, r2 - l2) + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (hi(l1, l1 + m) == hi(l2, l2 + m)) {
            l = m;
        } else {
            r = m;
        }
    }
    if (r1 - l1 == l) return 1;
    if (r2 - l2 == l) return 0;
    return a[l1 + l] < a[l2 + l];
}

int cmp2(int p, string &b) {
    int m = b.size();
    int i = p, j = 0;
    for (; i < n && j < m; i++, j++) {
        if (a[i] != b[j]) return (a[i] < b[j] ? 1 : -1);
    }
    if (j == m) return 0;
    return 1;
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= MAXN; i++) ps[i] = ps[i - 1] * P % MOD;
    cin >> a;
    n = a.size();
    for (auto c : a) pfs.push_back(H(pfs.back(), c - 'a'));

    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;
    sort(order.begin(), order.end(),
         [&](int x, int y) { return cmp(x, n, y, n); });

    int q;
    cin >> q;
    while (q--) {
        string b;
        cin >> b;
        int l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (cmp2(order[m], b) > 0) {
                l = m;
            } else {
                r = m;
            }
        }
        int L = l;
        l = -1, r = n;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (cmp2(order[m], b) >= 0) {
                l = m;
            } else {
                r = m;
            }
        }
        int R = l;
        cout << R - L << '\n';
    }
}