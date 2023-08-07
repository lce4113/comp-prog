// CodeForces Round #869: Problem C

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using pi = pair<int, int>;

void solve() {
  int n, q;
  cin >> n >> q;
  vi a(n);
  for (auto &x : a) cin >> x;
  vi inner(n, 0);
  for (int i = 1; i < n - 1; i++) {
    if (a[i - 1] >= a[i] && a[i] >= a[i + 1]) inner[i] = 1;
  }
  /* for (auto x : inner) cout << x << ' '; */
  /* cout << '\n'; */
  vi pfs(n + 1, 0);
  for (int i = 0; i < n; i++) pfs[i + 1] = pfs[i] + inner[i];
  /* for (auto x : pfs) cout << x << ' '; */
  /* cout << '\n'; */
  while (q--) {
    int l, r;
    cin >> l >> r;
    int ans = pfs[max(r - 1, l)] - pfs[l];
    cout << r - l + 1 - ans << '\n';
  }
}

int32_t main() {
  int t = 1;
  /* cin >> t; */
  while (t--) solve();
}
