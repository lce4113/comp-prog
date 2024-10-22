// CodeForces Round #929: Problem E

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> pfs(1, 0);
  for (int i = 1; i <= n; i++) {
    pfs.push_back(pfs.back() + a[i - 1]);
  }
  /* for (auto x : pfs) cout << x << ' '; */
  /* cout << '\n'; */
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, u;
    cin >> l >> u;
    int end = u + pfs[l - 1];
    auto r = --upper_bound(pfs.begin(), pfs.end(), end);
    /* cout << r - pfs.begin() << ' '; */
    if (u - (*r - pfs[l - 1]) >= (a[r - pfs.begin()] + 1) / 2) r++;
    int ans = r - pfs.begin();
    ans = max(ans, l);
    ans = min(ans, n);
    /* cout << u - (*r - pfs[l - 1]) << ' '; */
    /* cout << a[r - pfs.begin()] << ' '; */
    /* cout << *r << ' '; */
    cout << max(ans, 1) << ' ';
  }
  cout << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
