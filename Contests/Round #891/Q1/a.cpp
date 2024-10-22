// CodeForces Round #891: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  int odd = 0;
  for (auto x : a)
    if (x % 2) odd++;
  if (odd % 2) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
