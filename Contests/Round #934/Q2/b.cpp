// CodeForces Round #934: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n * 2);
  for (auto &x : a) cin >> x;
  map<int, vector<int>> mp;
  for (int i = 0; i < 2 * n; i++) mp[a[i]].push_back(i);
  /* for (auto x : mp) */
  /*   cout << x.first << ' ' << x.second[0] << ' ' << x.second[1] << '\n'; */
  vector<int> l, r, b;
  for (int i = 1; i <= n; i++) {
    if (mp[i][0] < n && mp[i][1] < n) {
      l.push_back(i);
    } else if (mp[i][0] >= n && mp[i][1] >= n) {
      r.push_back(i);
    } else {
      b.push_back(i);
    }
  }
  /* for (auto x : l) cout << x << ' '; */
  /* cout << '\n'; */
  /* for (auto x : r) cout << x << ' '; */
  /* cout << '\n'; */
  /* for (auto x : b) cout << x << ' '; */
  /* cout << '\n'; */
  vector<int> l_ans, r_ans;
  for (int i = 0; i < min(k, (int)l.size()); i++) {
    l_ans.push_back(l[i]);
    l_ans.push_back(l[i]);
    r_ans.push_back(r[i]);
    r_ans.push_back(r[i]);
  }
  int sz = l_ans.size();
  for (int i = 0; i < 2 * k - sz; i++) {
    /* cout << b[i] << '\n'; */
    l_ans.push_back(b[i]);
    r_ans.push_back(b[i]);
  }
  for (auto x : l_ans) cout << x << ' ';
  cout << '\n';
  for (auto x : r_ans) cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
