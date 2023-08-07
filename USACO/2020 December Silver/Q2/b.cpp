// USACO 2020 December Silver: Problem B

#include <bits/stdc++.h>
using namespace std;

#define int long long

using pi = pair<int, int>;
#define f first
#define s second
using vi = vector<int>;
#define pb push_back

int32_t main() {
  int n;
  cin >> n;

  vector<pi> points;
  vi xs(n), ys(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
    cin >> ys[i];
    points.pb({xs[i], ys[i]});
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());

  map<int, int> xm, ym;
  for (int i = 0; i < n; i++) {
    xm[xs[i]] = i;
    ym[ys[i]] = i;
  }
  for (auto &x : points) x.f = xm[x.f], x.s = ym[x.s];

  vector<vi> grid(n, vi(n, 0));
  for (auto p : points) grid[p.f][p.s] = 1;

  vector<vi> gridpfs(n + 1, vi(n + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      gridpfs[i + 1][k + 1] =
          gridpfs[i + 1][k] + gridpfs[i][k + 1] - gridpfs[i][k] + grid[i][k];
    }
  }

  /* for (auto r : gridpfs) { */
  /*   for (auto x : r) cout << x << ' '; */
  /*   cout << '\n'; */
  /* } */

  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (int k = i; k < n; k++) {
      int x1 = min(points[i].f, points[k].f),
          x2 = max(points[i].f, points[k].f);
      int y1 = min(points[i].s, points[k].s),
          y2 = max(points[i].s, points[k].s);
      x1++, x2++, y1++, y2++;
      /* cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << '\n'; */
      int above =
          gridpfs[x2][n] - gridpfs[x2][y2] - gridpfs[x1][n] + gridpfs[x1][y2];
      /* cout << gridpfs[x2][n] << ' ' << gridpfs[x2][y2] << ' ' <<
       * gridpfs[x1][n] */
      /*      << ' ' << gridpfs[x1][y2] << '\n'; */
      /* cout << '\n'; */
      int below = gridpfs[x2][y1 - 1] - gridpfs[x2][0] - gridpfs[x1][y1 - 1] +
                  gridpfs[x1][0];
      ans += (above + 1) * (below + 1);
      /* cout << above << ' ' << below << '\n'; */
    }
  }

  cout << ans << '\n';
}
