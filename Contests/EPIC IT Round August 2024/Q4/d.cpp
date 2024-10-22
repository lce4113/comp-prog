// CodeForces EPIC IT Round August 2024: Problem D

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n - 1), p(n);
  for (auto &x : a) cin >> x;
  for (auto &x : p) cin >> x;
  map<int, int> pos;
  for (int i = 0; i < n; i++) pos[p[i]] = i;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    // swap
    pos[p[x]] = y;
    pos[p[y]] = x;
    int tmp = p[x];
    p[x] = p[y];
    p[y] = tmp;
  }
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
