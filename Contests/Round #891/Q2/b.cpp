// CodeForces Round #891: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a;
  cin >> a;
  int n = a.size(), x = -2;
  for (int i = 0; i < n; i++) {
    /* cout << a[i] - '0' << '\n'; */
    if (a[i] - '0' >= 5) {
      x = i - 1;
      while (x >= 0 && a[x] == '4') x--;
      break;
    }
  }
  if (x == -1) {
    /* cout << "asdf\n"; */
    a = "1";
    for (int i = 0; i < n; i++) {
      a += '0';
    }
  } else if (x != -2) {
    a[x] = '0' + ((a[x] - '0') + 1);
    for (int i = x + 1; i < n; i++) a[i] = '0';
  }
  cout << a << '\n';
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
