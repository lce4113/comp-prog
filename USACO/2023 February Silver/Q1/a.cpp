// USACO 2023 February Silver: Problem A

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f first
#define s second
#define int long long

void solve() {
  int n, tc, tm;
  cin >> n >> tc >> tm;

  vector<vector<int>> friends;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    friends.pb({a, b, c});
  }

  int ans = 0;
  for (int i = 1; i <= tc; i++) {
    int y = LLONG_MAX;
    for (int k = 0; k < n; k++) {
      int x = friends[k][2] - i * friends[k][0];
      y = min(y, x / friends[k][1]);
    }
    y = min(y, tm);
    ans = max(ans, i + y);
    /* cout << i << ' ' << y << '\n'; */
  }

  cout << (tc + tm - ans) << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
