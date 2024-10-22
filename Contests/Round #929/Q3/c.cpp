// CodeForces Round #929: Problem C

#include <bits/stdc++.h>
using namespace std;

set<int> ks;
void rec(int n, int a, int b) {
  if (ks.count(n)) return;
  ks.insert(n);
  if (n % a == 0) rec(n / a, a, b);
  if (n % b == 0) rec(n / b, a, b);
}

void solve() {
  int a, b, l;
  cin >> a >> b >> l;
  rec(l, a, b);
  /* for (auto x : ks) cout << x << ' '; */
  /* cout << '\n'; */
  cout << ks.size() << '\n';
  ks.clear();
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
