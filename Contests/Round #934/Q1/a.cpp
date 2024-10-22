// CodeForces Round #934: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  if (k >= n - 1) {
    cout << "1\n";
    return;
  }
  cout << n << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
