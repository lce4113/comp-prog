// CodeForces EPIC IT Round August 2024: Problem C

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (auto &x : a) cin >> x.first >> x.second;
  int xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  int dist1 = (xs - xt) * (xs - xt) + (ys - yt) * (ys - yt);
  for (auto c : a) {
    int xd = xt - c.first;
    int yd = yt - c.second;
    int dist = xd * xd + yd * yd;
    if (dist <= dist1) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES" << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
