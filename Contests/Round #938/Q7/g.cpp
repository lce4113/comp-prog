// CodeForces Round #938: Problem G

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (auto &x : a) {
    for (auto &y : x) cin >> y;
  }
  for (auto x : a) {
    for (auto y : x) cout << y << ' ';
    cout << '\n';
  }
  cout << '\n';
  vector<vector<int>> b(n, vector<int>(m));
  b[n - 1][m - 1] = a[n - 1][m - 1];
  for (int i = m - 2; i >= 0; i--)
    b[n - 1][i] = gcd(a[n - 1][i], b[n - 1][i + 1]);
  for (int i = n - 2; i >= 0; i--)
    b[i][m - 1] = gcd(a[i][m - 1], b[i + 1][m - 1]);
  for (int i = n - 2; i >= 0; i--) {
    for (int k = m - 2; k >= 0; k--) {
      b[i][k] = max(gcd(b[i + 1][k], a[i][k]), gcd(a[i][k], b[i][k + 1]));
    }
  }
  for (auto x : b) {
    for (auto y : x) cout << y << ' ';
    cout << '\n';
  }
  cout << '\n';
  /* cout << b[0][0] << '\n'; */
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
