// CodeForces Round #938: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int sum = 0;
  for (auto x : a) sum += x;
  if (k >= sum) {
    cout << n << '\n';
    return;
  }
  int l = (k + 1) / 2, r = k / 2, L = 0, R = 0;
  for (int i = 0; i < n; i++) {
    l -= a[i];
    if (l < 0) break;
    L++;
  }
  for (int i = n - 1; i >= 0; i--) {
    r -= a[i];
    if (r < 0) break;
    R++;
  }
  /* cout << L << ' ' << R << '\n'; */
  cout << L + R << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
