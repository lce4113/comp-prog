// CodeForces Round #938: Problem F

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = 0;
  ans += (a % 2) && (b % 2) && (c % 2);
  ans += a / 2;
  ans += b / 2;
  ans += c / 2;
  ans += d / 2;
  cout << ans << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
