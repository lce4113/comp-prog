// CodeForces Round #875: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  vector<int> b(n - 1);
  for (int i = 0; i < n - 1; i++) b[i] = abs(a[i + 1] - a[i]);
  sort(b.rbegin(), b.rend());
  /* for (auto x : b) cout << x << ' '; */
  /* cout << '\n'; */
  int ans = 0;
  for (int i = k - 1; i < n - 1; i++) ans += b[i];
  cout << ans << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
