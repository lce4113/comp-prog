// CodeForces Round #936: Problem C

#include <bits/stdc++.h>
using namespace std;

#define MOD 1'000'000'007
#define int long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int mn = 0, ans = INT_MIN, curr = 0;
  for (auto x : a) curr += x, mn = min(mn, curr), ans = max(ans, curr - mn);
  int other = curr - ans;
  /* cout << ans << ' '; */
  ans %= MOD;
  for (int i = 0; i < k; i++) ans *= 2, ans %= MOD;
  /* cout << ans << ' '; */
  ans += other, ans %= MOD;
  ans += MOD, ans %= MOD;
  cout << ans << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
