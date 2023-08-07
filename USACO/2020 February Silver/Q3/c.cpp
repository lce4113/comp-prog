// USACO 2020 February Silver: Problem C

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int n;
vector<int> clocks;
map<int, vector<int>> edges;

int rec(int curr, int parent) {
  auto children = edges[curr];
  int tot = 0;
  for (int i = 0; i < children.size(); i++) {
    if (children[i] == parent) continue;
    tot += rec(children[i], curr);
  }
  /* cout << curr << ' ' << clocks[curr] << ' ' << tot << '\n'; */
  return ((clocks[curr] - tot) % 12 + 12) % 12;
}

int32_t main() {
  freopen("clocktree.in", "r", stdin);
  freopen("clocktree.out", "w", stdout);

  cin >> n;
  clocks.resize(n);
  for (auto &c : clocks) cin >> c;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edges[a].pb(b);
    edges[b].pb(a);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x = rec(i, -1);
    /* cout << i << ' ' << x << '\n'; */
    if (x == 0) {
      cout << n << '\n';
      return 0;
    }
    if (x == 1) ans++;
  }
  cout << ans << '\n';
}
