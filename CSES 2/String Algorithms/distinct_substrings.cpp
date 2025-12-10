// CSES String Algorithms: Distinct Substrings

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

int lcp(int l1, int r1, int l2, int r2) {
    int l = 0, r = min(r1 - l1, r2 - l2) + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (hi(l1, l1 + m) == hi(l2, l2 + m)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

bool cmp(int l1, int r1, int l2, int r2) {
    int l = lcp(l1, r1, l2, r2);
    if (l == r1 - l1) return 1;
    if (l == r2 - l2) return 0;
    return a[l1 + l] < a[l2 + l];
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

    int ans = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++) {
        ans -= lcp(order[i], n, order[i + 1], n);
    }
    cout << ans << '\n';
}