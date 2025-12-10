// CSES Advanced Techniques: Knuth Division

#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> pfs(1, 0);
int ans = 0;

void rec(int l, int r) {
    if (r - l == 1) return;
    int tot = pfs[r] - pfs[l];
    ans += tot;
    auto p =
        upper_bound(pfs.begin(), pfs.end(), tot / 2 + pfs[l]) - pfs.begin();
    int r1 = pfs[p] - pfs[l];
    int r2 = pfs[p - 1] - pfs[l];
    int m = abs(tot - r1 - r1) < abs(tot - r2 - r2) ? p : p - 1;
    rec(l, m);
    rec(m, r);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (auto x : a) pfs.push_back(pfs.back() + x);

    rec(0, n);
    cout << ans << '\n';
}