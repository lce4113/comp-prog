// CodeForces Round #925: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n <= 2 + 26) {
    char x = 'a' + (n - 2 - 1);
    cout << "aa" << x << '\n';
  } else if (n <= 1 + 26 + 26) {
    char x = 'a' + (n - 27 - 1);
    cout << "a" << x << 'z' << '\n';
  } else {
    char x = 'a' + (n - 52 - 1);
    cout << x << "zz" << '\n';
  }
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
