// CodeForces Round #869: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return;
  }
  if (n % 2) {
    cout << "-1\n";
    return;
  }
  for (int i = 1; i < n; i += 2) cout << i + 1 << ' ' << i << ' ';
  cout << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
