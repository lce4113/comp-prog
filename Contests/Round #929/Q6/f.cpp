// CodeForces Round #929: Problem F

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (auto &x : a) {
    for (auto &y : x) cin >> y;
  }
  vector<vector<int>> b(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < m; k++) {
      b[i][k] = a[(i + k) % n][k];
    }
  }
  for (int i = n-1; i > 0; i--) {
    for (int k = m-1; k >= 0; k--) {
      if (b[(i+1)%n][k-1])
    }
  }
  for (auto &x : b) {
    for (auto &y : x) cout << y << ' ';
    cout << '\n';
  }
  int ry = 0, t = 0;
  for (int rx = 0; rx < m - 1; rx++) {
    int start = ry;
    while (true) {
      if (b[ry][rx + 1] == 0) break;
      if (b[(ry + 1) % n][rx] == 1) {
        cout << -1 << '\n';
        return;
      }
      t++, ry += 2, ry %= n;
      if (ry == start) {
        cout << -1 << '\n';
        return;
      }
    }
    t++;
  }
  cout << t << ' ';
  cout << ry << ' ';
  t -= (ry - (m - 1 - (-1))) % n;
  cout << t << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
