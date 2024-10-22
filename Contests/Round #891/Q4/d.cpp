// CodeForces Round #891: Problem D

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  int mx = -2e9;
  for (int i = 0; i < n; i++) {
    mx = max(mx, a[i] - b[i]);
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (a[i] - b[i] == mx) ans.push_back(i + 1);
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
