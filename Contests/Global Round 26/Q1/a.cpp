// CodeForces Global Round 26: Problem A

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  if (a[0] == a[n - 1]) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  cout << 'R' << 'B';
  for (int i = 2; i < n; i++) {
    cout << 'R';
  }
  cout << '\n';
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) solve();
}
