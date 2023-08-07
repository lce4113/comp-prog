// USACO 2019 US Open Silver: Problem A

#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
#define ll long long
#define pb push_back
#define f first
#define s second

void solve() {
  ifstream cin("leftout.in");
  /* ofstream cout("leftout.out"); */

  int n;
  cin >> n;
  vector<vi> a(n, vi(n));
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      char x;
      cin >> x;
      a[i][k] = (x == 'R' ? 1 : 0);
    }
  }
  cout << a[701][736] << ' ';
  cout << a[702][736] << ' ';
  cout << a[703][736] << '\n';
  cout << a[701][737] << ' ';
  cout << a[702][737] << ' ';
  cout << a[703][737] << '\n';
  cout << a[701][738] << ' ';
  cout << a[702][738] << ' ';
  cout << a[703][738] << '\n';

  map<vi, vi> x;
  for (int i = 0; i < n; i++) {
    int tot = 0;
    for (int k = 0; k < n; k++) tot += a[i][k];
    if (tot == n / 2 && a[i][0])
      for (int k = 0; k < n; k++) a[i][k] = 1 - a[i][k];
    if (tot > n / 2)
      for (int k = 0; k < n; k++) a[i][k] = 1 - a[i][k];
    x[a[i]].pb(i);
  }

  if (x.size() == 1) {
    cout << -1;
    return;
  }
  if (n == 2) {
    cout << "1 1\n";
    return;
  }

  vi b, d;
  int c;
  for (auto y : x) {
    /* for (auto z : y.f) cout << z << ' '; */
    /* cout << '\n'; */
    /* for (auto z : y.s) cout << z << ' '; */
    /* cout << '\n'; */
    if (y.s.size() == 1) {
      b = y.f;
      c = y.s[0];
    } else {
      d = y.f;
    }
  }

  int z = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == d[i]) z++;
  }
  for (int i = 0; i < n; i++) {
    if (z == 1 && b[i] == d[i]) {
      cout << c + 1 << ' ' << i + 1 << '\n';
      return;
    }
    if (z == n - 1 && b[i] != d[i]) {
      cout << c + 1 << ' ' << i + 1 << '\n';
      return;
    }
  }
}

int32_t main() {
  int t = 1;
  /* cin >> t; */
  while (t--) solve();
}
