// CodeForces Round #936: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  sort(a.begin(), a.end());
  int med = a[(n - 1) / 2], h = 0;
  for (auto x : a)
    if (x > med) h++;
  cout << n / 2 + 1 - h << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
