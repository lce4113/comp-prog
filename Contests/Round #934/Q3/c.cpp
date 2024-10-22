// CodeForces Round #934: Problem C

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  map<int, int> mp;
  for (auto x : a) mp[x]++;
  /* for (auto x : mp) cout << x.first << ' ' << x.second << '\n'; */
  vector<int> one;
  int zero = -1;
  for (int i = 0; i <= n; i++) {
    if (zero == -1 && !mp[i]) zero = i;
    if (mp[i] == 1) one.push_back(i);
  }
  /* for (auto x : one) cout << x << ' '; */
  /* cout << '\n'; */
  if (one.size() <= 1)
    cout << zero << '\n';
  else
    cout << min(zero, one[1]) << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
