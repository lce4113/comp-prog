// CodeForces Round #891: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<pair<int, int>> b;
  for (int i = 0; i < n; i++) b.push_back({a[i], i});
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<int> c(n);
  for (int i = 0; i < n; i++) c[b[i].second] = i;
  /* for (auto x : c) cout << x << ' '; */
  /* cout << '\n'; */

  vector<int> pfs(1, 0);
  for (auto x : a) pfs.push_back(pfs.back() + x);
  for (int k = 0; k < n; k++) {
    int i = c[k];
    int pre = a[i] * (i + 1) - pfs[i + 1];
    int post = pfs.back() - pfs[i] - a[i] * (n - i);
    cout << pre + post + n << ' ';
    /* cout << pre << ' ' << post << ' ' << n << '\n'; */
  }
  cout << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
