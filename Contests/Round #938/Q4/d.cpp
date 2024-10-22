// CodeForces Round #938: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  map<int, int> b;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    b[x]++;
  }
  int curr = 0;
  map<int, int> nums;
  for (int i = 0; i < m; i++) {
    nums[a[i]]++;
    if (nums[a[i]] <= b[a[i]]) curr++;
  }
  int ans = 0;
  for (int l = 0, r = m; r < n; l++, r++) {
    /* cout << curr << ' '; */
    if (curr >= k) ans++;
    if (nums[a[l]] <= b[a[l]]) curr--;
    nums[a[l]]--;
    nums[a[r]]++;
    if (nums[a[r]] <= b[a[r]]) curr++;
  }
  /* cout << curr << '\n'; */
  if (curr >= k) ans++;
  cout << ans << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
