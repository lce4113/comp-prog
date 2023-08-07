// ––– USACO 2021 February Silver: Problem C –––

#include <bits/stdc++.h>
using namespace std;

#define int long long
using vi = vector<int>;
#define pb push_back

int n;
vector<vi> grid;

int rowcount(vi row) {
  int consec = 0, ans = 0;
  for (int i = 0; i < row.size(); i++) {
    if (row[i])
      consec++;
    else
      consec = 0;
    ans += consec;
  }
  return ans;
}

int count(int mn) {
  vector<vi> ok = grid;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      ok[i][k] = (ok[i][k] >= mn);
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    vi curr(n, 1);
    for (int k = i; k < n; k++) {
      for (int i = 0; i < n; i++) curr[i] &= ok[k][i];
      ans += rowcount(curr);
      /* cout << rowcount(curr) << ' '; */
    }
    /* cout << '\n'; */
  }
  /* cout << '\n'; */
  return ans;
}

int32_t main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    vector<int> r(n);
    grid.pb(r);
    for (int k = 0; k < n; k++) cin >> grid[i][k];
  }

  int ans = count(100) - count(101);
  /* cout << count(100) << ' ' << count(101) << '\n'; */
  cout << ans << '\n';
}
