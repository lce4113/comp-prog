// CodeForces Round 959: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (auto &x : a) {
    for (auto &y : x) cin >> y;
  }
  /* for (auto &x : a) { */
  /*   for (auto &y : x) cout << y << ' '; */
  /*   cout << '\n'; */
  /* } */
  if (n == 1 && m == 1) {
    cout << "-1\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < m; k++) {
      cout << a[(i + 1) % n][(k + 1) % m] << ' ';
    }
    cout << '\n';
  }
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
