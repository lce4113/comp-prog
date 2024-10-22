// CodeForces Round 959: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> pfs(1, 0);
  for (auto b : a) pfs.push_back(pfs.back() + b);
  vector<int> p(n + 1, 0);
  for (int i = n - 1; i >= 0; i--) {
    auto it = upper_bound(pfs.begin(), pfs.end(), pfs[i] + x);
    int k = it - pfs.begin();
    /* cout << i << ' ' << k << '\n'; */
    if (k > n) continue;
    p[i] = 1 + p[k];
  }
  /* for (auto x : p) cout << x << ' '; */
  /* cout << '\n'; */
  int ans = n * (n + 1) / 2;
  for (auto x : p) ans -= x;
  cout << ans << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
