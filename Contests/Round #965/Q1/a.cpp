// CodeForces Round #965: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y, k;
  cin >> x >> y >> k;
  for (int i = 1; i <= k / 2; i++) {
    cout << x << ' ' << y + i << '\n';
    cout << x << ' ' << y - i << '\n';
  }
  if (k % 2) {
    cout << x << ' ' << y << '\n';
  }
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
