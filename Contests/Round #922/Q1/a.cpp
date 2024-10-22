// CodeForces Round #922: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  /* for (int i = 2; i <= max(n, m); i++) { */
  int two_h = m / 2 * n;
  /* int two_v = m % 2; */
  /* int ans = two_h - two_v; */
  /* } */

  cout << two_h << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
