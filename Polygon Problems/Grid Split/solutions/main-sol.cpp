// ––– "Grid Split" - Solution (Main) –––

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;

  // create prefix sum arrays and find the total sum
  vector<ll> pfs_a, pfs_b;
  pfs_a.push_back(0), pfs_b.push_back(0);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    pfs_a.push_back(pfs_a.back() + a[i]);
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    pfs_b.push_back(pfs_b.back() + b[i]);
    sum += b[i];
  }

  // if the total sum is odd, output 0 and exit
  if (sum % 2) {
    cout << 0 << '\n';
    return;
  }

  // do two pointers on the prefix sum arrays to find
  // pairs of integers that sum to half the total sum
  ll half_sum = sum / 2;
  int ans = 0;
  for (int i = 0, k = n; i <= n && k >= 0;) {
    ll pfs_sum = pfs_a[i] + pfs_b[k];
    if (pfs_sum < half_sum) {
      i++;
    } else if (pfs_sum > half_sum) {
      k--;
    } else {
      i++, k--, ans++;
    }
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
