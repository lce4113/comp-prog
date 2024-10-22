// CodeForces Round 959: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  int a = n + 1, b = n + 1;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      a = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (t[i] == '1') {
      b = i;
      break;
    }
  }
  if (a > b) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
