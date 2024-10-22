// CodeForces Round #963: Problem D

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int x = (n % k == 0 ? k : n % k);
  vector<int> meds;
  vector<int> dp(n);
  for (int i = 0; i < x; i++) {
    int mx = -1;
    for (int y = i; y < n; y += k) mx = max(mx, a[y]);
    meds.push_back(mx);
  }
  sort(meds.begin(), meds.end());
  int ans = meds[(meds.size() - 1) / 2];
  cout << ans << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
