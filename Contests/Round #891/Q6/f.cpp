// CodeForces Round #891: Problem F

#include <bits/stdc++.h>
using namespace std;

bool eq(double a, double b) { return abs(a - b) <= 0.001; }
bool whole(double a) { return eq(a, (int)a); }

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;

  map<int, int> mp;
  for (auto x : a) mp[x]++;

  int q;
  cin >> q;
  while (q--) {
    int c, d;
    cin >> c >> d;
    double x = (c - sqrt(c * c - 4 * d)) / 2;
    double y = (c + sqrt(c * c - 4 * d)) / 2;
    /* cout << x << ' ' << y << '\n'; */
    if (!whole(x)) {
      cout << "0 ";
      continue;
    }
    if (x == y) {
      int ans = mp[(int)x] * (mp[(int)x] - 1) / 2;
      cout << ans << ' ';
      continue;
    }
    int ans = mp[(int)x] * mp[(int)y];
    cout << ans << ' ';
  }
  cout << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
