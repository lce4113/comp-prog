// CodeForces Round #952: Problem D

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, m;
  cin >> n >> m;
  int tx = 0, ty = 0, tn = 0;
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < m; k++) {
      char x;
      cin >> x;
      if (x == '#') tx += k, ty += i, tn++;
    }
  }
  cout << ty / tn + 1 << ' ' << tx / tn + 1 << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
