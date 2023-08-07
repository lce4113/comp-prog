// CodeForces Round #875: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  /* int ans = 1, x = 1073741823; */
  int ans = 0, x = pow(2, 30) - 1;
  for (int i = 0; i < n; i++) {
    x &= a[i];
    if (x == 0) {
      ans++;
      x = pow(2, 30) - 1;
    }
  }
  cout << max(ans, 1) << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
