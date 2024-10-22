// CodeForces Round #952: Problem F

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int h, n;
  cin >> h >> n;
  vector<int> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;
  int tl = 0, tr = 1e12;
  for (int mid = (tl + tr) / 2; tr >= tl + 1; mid = (tl + tr) / 2) {
    int H = h;
    for (int i = 0; i < n; i++) {
      int count = (mid + b[i] - 1) / b[i];
      H -= count * a[i];
      if (H < 0) break;
    }
    /* cout << tl << ' ' << tr << '\n'; */
    if (H <= 0) tr = mid;
    if (H > 0) tl = mid + 1;
  }
  /* cout << tl << ' ' << tr << '\n'; */
  cout << tl << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
