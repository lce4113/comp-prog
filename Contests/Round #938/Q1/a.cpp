// CodeForces Round #938: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  if (b < 2 * a) {
    int ans = n / 2 * b + (n % 2) * a;
    cout << ans << '\n';
    return;
  }
  int ans = n * a;
  cout << ans << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
