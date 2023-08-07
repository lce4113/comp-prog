// USACO 2020 December Silver: Problem A

#include <bits/stdc++.h>
using namespace std;

#define int long long
using vi = vector<int>;
#define pb push_back

int n;
map<int, vi> tree;

int ans = 0;

void rec(int curr, int p) {
  if (tree[curr].size() == 1) return;
  int children = tree[curr].size() - (p != 0);
  /* cout << children << ' '; */
  ans += ceil(log2(children + 1));
  ans += children;
  for (auto x : tree[curr]) {
    if (x == p) continue;
    rec(x, curr);
  }
}

int32_t main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].pb(b);
    tree[b].pb(a);
  }

  rec(1, 0);
  cout << ans << '\n';
}
