// CodeForces EPIC IT Round August 2024: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  bool A = true, B = true;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) A = false;
    if (a[i] != b[n - 1 - i]) B = false;
  }
  if (A || B) {
    cout << "Bob" << '\n';
    return;
  }
  cout << "Alice" << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
