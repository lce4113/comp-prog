// ––– "Grid Split" - Solution (Casual) –––

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> g(2, vector<int>(n));
  for (auto &row : g) {
    for (auto &x : row) cin >> x;
  }

  vector<vector<ll>> pfs(2, vector<ll>(1, 0));
  ll sum = 0;
  for (int x = 0; x < 2; x++) {
    for (int i = 0; i < n; i++) {
      pfs[x].push_back(pfs[x].back() + g[x][i]);
      sum += g[x][i];
    }
  }

  if (sum % 2) {
    cout << 0 << '\n';
    return;
  }

  ll half_sum = sum / 2;
  int ans = 0;
  for (int i = 0, k = n; i <= n && k >= 0;) {
    ll pfs_sum = pfs[0][i] + pfs[1][k];
    if (pfs_sum == half_sum) i++, k--, ans++;
    if (pfs_sum < half_sum) i++;
    if (pfs_sum > half_sum) k--;
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
