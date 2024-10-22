// CodeForces Round #952: Problem E

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  int ca = k, ans = 0;
  for (int a = 1; a <= x; a++) {
    if (ca % a) continue;
    int cb = ca / a;
    for (int b = 1; b <= y; b++) {
      if (cb % b) continue;
      int cc = cb / b;
      if (cc > z) continue;
      int curr = (x - a + 1) * (y - b + 1) * (z - cc + 1);
      ans = max(ans, curr);
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
