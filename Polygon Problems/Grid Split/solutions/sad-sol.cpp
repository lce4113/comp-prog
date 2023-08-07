// ––– "Grid Split" - Solution (In O(nlog(n)) Time) –––

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;

  vector<ll> pfs_a(1, 0), pfs_b(1, 0);
  set<ll> matches;
  matches.insert(0);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    pfs_a.push_back(pfs_a.back() + a[i]);
    matches.insert(pfs_a.back());
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    pfs_b.push_back(pfs_b.back() + b[i]);
    sum += b[i];
  }

  if (sum % 2) {
    cout << 0 << '\n';
    return;
  }

  ll half_sum = sum / 2;
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += matches.count(half_sum - pfs_b[i]);
  }

  cout << ans << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
