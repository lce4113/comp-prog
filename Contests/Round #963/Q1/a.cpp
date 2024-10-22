// CodeForces Round #963: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  map<char, int> mp;
  for (auto x : s) {
    mp[x]++;
  }
  int ans = 0;
  /* for (auto x : mp) { */
  /*   cout << x.first << ' ' << x.second << '\n'; */
  /* } */
  for (auto y : "ABCD") {
    ans += min(mp[y], n);
  }
  cout << ans << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
