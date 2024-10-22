// CodeForces Round #963: Problem C

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int mx = 0;
  for (auto &x : a) {
    cin >> x;
    mx = max(mx, x);
  }
  int K = 2 * k;
  for (auto &x : a) {
    x += (mx - x) / K * K;
    if (mx - x > k) x += 2 * k;
  }
  sort(a.begin(), a.end());
  if (a[n - 1] - a[0] >= k) {
    cout << "-1\n";
    return;
  }
  cout << a[n - 1] << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
