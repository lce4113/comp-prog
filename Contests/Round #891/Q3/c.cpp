// CodeForces Round #891: Problem C

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int m = n * (n - 1) / 2;
  vector<int> a(m);
  for (auto &x : a) cin >> x;

  map<int, int> mp;
  for (auto x : a) mp[x]++;
  int x = n - 1;
  vector<int> ans;
  for (auto &p : mp) {
    /* cout << p.first << ' ' << p.second << '\n'; */
    while (p.second != 0) {
      p.second -= x;
      x--;
      ans.push_back(p.first);
    }
  }
  for (auto y : ans) cout << y << ' ';
  cout << ans.back();
  cout << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
