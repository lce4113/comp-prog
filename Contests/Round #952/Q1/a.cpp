// CodeForces Round #952: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a, b, c, d;
  cin >> a >> b;
  cout << b[0] << a[1] << a[2] << ' ';
  cout << a[0] << b[1] << b[2] << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
