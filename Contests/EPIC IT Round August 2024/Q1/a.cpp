// CodeForces EPIC IT Round August 2024: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int ans = min(n, k) * min(m, k);
  cout << ans << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
