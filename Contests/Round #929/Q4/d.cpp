// CodeForces Round #929: Problem D

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  if (n == 1) {
    cout << "YES\n";
    return;
  }
  if (a[0] != a[1]) {
    cout << "YES\n";
    return;
  }
  for (int i = 2; i < n; i++) {
    if (a[i] % a[0]) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
