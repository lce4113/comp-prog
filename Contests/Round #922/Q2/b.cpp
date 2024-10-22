// CodeForces Round #922: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  map<int, int> mp;
  for (int i = 0; i < n; i++) mp[a[i]] = b[i];

  for (int i = 1; i <= n; i++) cout << i << ' ';
  cout << '\n';
  for (int i = 1; i <= n; i++) cout << mp[i] << ' ';
  cout << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
