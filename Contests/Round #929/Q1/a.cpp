// CodeForces Round #929: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int sum = 0;
  for (auto x : a) sum += abs(x);
  cout << sum << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
