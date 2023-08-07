// USACO 2023 January Silver: Problem B

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define int long long

int32_t main() {
  int n;
  cin >> n;
  int num[n + 1][n + 1];
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      num[i][k] = 1;
    }
    num[i][n] = 0;
    num[n][i] = 0;
  }
  pair<int, int> to[n][n];
  int right[n], down[n];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      char x;
      cin >> x;
      if (x == 'D') {
        to[i][k] = {i + 1, k};
        num[i + 1][k] += num[i][k];
      } else {
        to[i][k] = {i, k + 1};
        num[i][k + 1] += num[i][k];
      }
    }
    cin >> right[i];
  }
  for (int i = 0; i < n; i++) cin >> down[i];
  for (int i = 0; i < n; i++) {
    ans += right[i] * num[i][n];
    ans += down[i] * num[n][i];
  }
  cout << ans << '\n';

  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    int xi = x, yi = y;
    int nm = num[x][y];
    while (x != n && y != n) {
      pair<int, int> z = to[x][y];
      x = z.f, y = z.s;
      num[x][y] -= nm;
    }
    if (y == n) {
      ans -= nm * right[x];
    } else {
      ans -= nm * down[y];
    }
    x = xi, y = yi;
    if (to[x][y].f == x) {
      to[x][y] = {x + 1, y};
    } else {
      to[x][y] = {x, y + 1};
    }
    while (x != n && y != n) {
      pair<int, int> z = to[x][y];
      x = z.f, y = z.s;
      num[x][y] += nm;
      /* cout << x << ' ' << y << '\n'; */
    }
    if (y == n) {
      /* cout << nm << ' ' << right[x] << '\n'; */
      ans += nm * right[x];
    } else {
      ans += nm * down[y];
      /* cout << nm << ' ' << down[y] << '\n'; */
    }
    cout << ans << '\n';
  }
}
