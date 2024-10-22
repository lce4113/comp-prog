// CodeForces Round #934: Problem E

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  /* for (auto x : a) { */
  /*   for (auto y : x) cout << y << ' '; */
  /*   cout << '\n'; */
  /* } */
  int mn = INT_MAX, mi;
  for (int i = 1; i <= n; i++) {
    queue<pair<int, int>> b;
    b.push({i, 0});
    set<int> done;
    int mx = 0;
    while (b.size()) {
      auto curr = b.front();
      b.pop();
      if (done.count(curr.first)) continue;
      mx = max(mx, curr.second);
      /* cout << curr.first << ' ' << curr.second << '\n'; */
      for (auto x : a[curr.first]) b.push({x, curr.second + 1});
      done.insert(curr.first);
    }
    if (mx < mn) mi = i, mn = mx;
    /* cout << '\n'; */
  }
  /* cout << "hi\n"; */
  cout << mn + 1 << '\n';
  for (int i = 0; i <= mn; i++) cout << mi << ' ' << i << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
