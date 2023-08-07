// USACO 2020 February Silver: Problem B

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define int long long
#define bk back()

const int MOD = 1e9 + 7;

int32_t main() {
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);

  int n;
  cin >> n;

  vector<pair<int, int>> coords(n);
  for (auto &x : coords) cin >> x.f >> x.s;
  sort(coords.begin(), coords.end());

  map<int, vector<int>> pfs_row, pfs_col;
  for (auto &c : coords) {
    if (!pfs_row[c.s].size()) pfs_row[c.s].pb(0);
    if (!pfs_col[c.f].size()) pfs_col[c.f].pb(0);
    pfs_row[c.s].pb(pfs_row[c.s].bk + c.f);
    pfs_col[c.f].pb(pfs_col[c.f].bk + c.s);
  }

  /* for (auto &x : pfs_row) { */
  /*   cout << x.f << " : "; */
  /*   for (auto &y : x.s) { */
  /*     cout << y << ", "; */
  /*   } */
  /*   cout << '\n'; */
  /* } */
  /* cout << '\n'; */

  map<pair<int, int>, pair<int, int>> coords_with_ind;
  for (auto &c : coords) coords_with_ind[c] = {0, 0};
  map<int, vector<int>> rows, cols;
  for (auto &c : coords) {
    rows[c.s].pb(c.f);
    coords_with_ind[c].f = rows[c.s].size() - 1;
  }
  for (auto &c : coords) {
    cols[c.f].pb(c.s);
    coords_with_ind[c].s = cols[c.f].size() - 1;
  }

  int ans = 0;
  for (auto &c : coords_with_ind) {
    int row_val = c.f.f, col_val = c.f.s;
    int row_ind = c.s.f + 1, col_ind = c.s.s + 1;
    /* cout << row_val << ' ' << row_ind << ", " << col_val << ' ' << col_ind */
    /*      << '\n'; */
    int x_left = row_val * row_ind - pfs_row[col_val][row_ind];
    int y_below = col_val * col_ind - pfs_col[row_val][col_ind];
    int x_right = pfs_row[col_val].bk - pfs_row[col_val][row_ind] -
                  row_val * (pfs_row[col_val].size() - 1 - row_ind);
    int y_above = pfs_col[row_val].bk - pfs_col[row_val][col_ind] -
                  col_val * (pfs_col[row_val].size() - 1 - col_ind);
    /* cout << x_left << ' ' << x_right << ", " << y_below << ' ' << y_above */
    /*      << "\n\n"; */
    ans += x_left * (y_below + y_above);
    ans %= MOD;
    ans += x_right * (y_below + y_above);
    ans %= MOD;
  }

  cout << ans << '\n';
}
