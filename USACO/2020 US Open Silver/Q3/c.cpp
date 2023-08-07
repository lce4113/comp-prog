// USACO 2020 US Open Silver: Problem C

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second

int32_t main() {
  ifstream cin("moop.in");
  ofstream cout("moop.out");

  int n;
  cin >> n;
  vector<pair<int, int>> points(n);
  for (auto &p : points) cin >> p.f >> p.s;
  sort(points.begin(), points.end());

  vector<int> mns(n), mxs(n);
  int mn = INT_MAX, mx = -INT_MAX;
  for (int i = 0; i < points.size(); i++) {
    mn = min(mn, points[i].s);
    mns[i] = mn;
  }
  for (int i = points.size() - 1; i >= 0; i--) {
    mx = max(mx, points[i].s);
    mxs[i] = mx;
  }

  int ans = 1;
  for (int i = 0; i < points.size() - 1; i++)
    if (mns[i] > mxs[i + 1]) ans++;
  cout << ans << '\n';
}
