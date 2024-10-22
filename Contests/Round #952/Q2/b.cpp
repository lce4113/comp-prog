// CodeForces Round #952: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int mx = -1, mi;
  for (int i = 2; i <= n; i++) {
    int ans = 0;
    for (int curr = i; curr <= n; curr += i) {
      ans += curr;
    }
    if (ans > mx) mx = ans, mi = i;
  }
  cout << mi << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
