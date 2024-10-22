// CodeForces Round #929: Problem B

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int sum = 0;
  for (auto x : a) sum += x;
  if (sum % 3 == 0) {
    cout << 0 << '\n';
  } else if (sum % 3 == 2) {
    cout << 1 << '\n';
  } else {
    bool all_two = true;
    for (auto x : a) {
      if (x % 3 == 1) all_two = false;
    }
    if (all_two) {
      cout << 2 << '\n';
    } else {
      cout << 1 << '\n';
    }
  }
}

int32_t main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
}
